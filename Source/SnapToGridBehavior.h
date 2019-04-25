namespace juce
{
    namespace AnimatedPositionBehaviours
    {
        class Screen {
        public:
            
            int start() {
                return 0;
            }
            
            int end() {
                return screenWidth;
            }
            
            void setCurrentScreen(int currentScreen) {
                this->currentScreen = currentScreen;
            }
            
            int getCurrentScreen() {
                return currentScreen;
            }
            
            void setNumberOfScreens(int numberOfScreens) {
                this->numberOfScreens = numberOfScreens;
            }
            
            int getNumberOfScreens() {
                return numberOfScreens;
            }
            
            void setScreenWidth(int screenWidth) {
                this->screenWidth = screenWidth;
            }
            
            int getScreenWidth() {
                return screenWidth;
            }
            
            void movePageForward() {
                currentScreen++;
            }
            
            void movePageBackward() {
                currentScreen--;
            }
            
        private:
            int numberOfScreens;
            int screenWidth;
            int currentScreen;
        };
        
        class SnapToPageWithMomentum
        {
        public:
            SnapToPageWithMomentum() {
                log = Logger::getCurrentLogger();
            }
            
            void setFriction (double newFriction) noexcept {
                damping = 1.0 - newFriction;
            }
            
            Screen getScreen() {
                return screen;
            }
            
            void setCurrentScreen(int currentScreen) {
                screen.setCurrentScreen(currentScreen);
            }
            
            void setNumberOfScreens(int numberOfScreens) {
                screen.setNumberOfScreens(numberOfScreens);
            }
            
            void setScreenWidth(int screenWidth) {
                screen.setScreenWidth(screenWidth);
            }
            
            /** Called by the AnimatedPosition class. This tells us the position and
             velocity at which the user is about to release the object.
             The velocity is measured in units/second.
             */
            void releasedWithVelocity (double /*position*/, double releaseVelocity) noexcept
            {
                velocity = releaseVelocity;
                //log -> writeToLog("Release Velocity: " + String(releaseVelocity) + " isDecisionMade: " + String(isPageSwipeIndicated ? "true" : "false"));
                if (std::abs (velocity) > thresholdVelocity) {
                    isPageSwipeIndicated = true;
                }
            }
            
            /** Called by the AnimatedPosition class to get the new position, after
             the given time has elapsed.
             */
            double getNextPosition (double oldPosition, double elapsedSeconds) noexcept
            {
                //log->writeToLog(String(oldPosition));
                velocity *= damping;
                
                if (std::abs (velocity) > decisionVelocity) {
                    return oldPosition + velocity * elapsedSeconds;
                }
                if (velocity < 0 && isNotLastScreen()) {
                    velocity = 0;
                    if (isCursorBeyondThresholdOfLeftSwipe(oldPosition) || isPageSwipeIndicated) {
                        double nextPosition = 800;
                        screen.movePageForward();
                        isPageSwipeIndicated = false;
                        return nextPosition;
                    } else {
                        return 0;
                    }
                }
                if (oldPosition < 0 ) {
//                    if (oldPosition < (-screenWidth / 2.0) || isPageSwipeIndicated) {
//                        oldPosition = -screenWidth;
//                        currentScreen--;
//                        isPageSwipeIndicated = false;
//                    } else {
//                        oldPosition = 0;
//                    }
                }
                velocity = 0;
                return velocity;
            }
            
            /** Called by the AnimatedPosition class to check whether the object
             is now stationary.
             */
            bool isStopped (double position) const noexcept {
                return velocity == 0.0;
            }
            
        private:
            constexpr static double minimumVelocity = 0.5;
            constexpr static double decisionVelocity = 80;
            constexpr static double thresholdVelocity = 2000;
            
            double damping = 0.95;
            double velocity = 0;
            bool isPageSwipeIndicated = false;
            Logger* log;
            Screen screen;
            
            bool isNotLastScreen() {
                return !(screen.getCurrentScreen() == (screen.getNumberOfScreens() - 1));
            }
            
            bool isNotFirstScreen() {
                return !(screen.getCurrentScreen() == 0);
            }
            
            bool isCursorBeyondThresholdOfLeftSwipe(double cursorPosition) {
                return cursorPosition < (screen.end() - (screen.getScreenWidth() / 2.0)) ;
            }
            
            bool isCursorBeyondThresholdOfRightSwipe(double cursorPosition) {
                return cursorPosition > (screen.start() + (screen.getScreenWidth() / 2.0));
            }
        };
    }
    
} // namespace juce

