/*
  ==============================================================================

    TestSwiper.cpp
    Created: 1 Sep 2018 7:11:44pm
    Author:  Akash Murthy

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "BlackSceen.cpp"
#include "GlobalEffectConfigurationView.cpp"
#include "SnapToGridBehavior.h"

class TestSwiper : public Component,
AnimatedPosition<AnimatedPositionBehaviours::SnapToPageWithMomentum>::Listener {
    
public:
    
    TestSwiper() {
        log = Logger::getCurrentLogger();
        setSize(800, 600);
        addAndMakeVisible(screen1);
        addAndMakeVisible(screen2);
        addAndMakeVisible(screen3);
        
        animatedPosition.addListener(this);
        //animatedPosition.setLimits(Range<double>(0,800));
        animatedPosition.behaviour.setCurrentScreen(0);
        animatedPosition.behaviour.setNumberOfScreens(3);
        animatedPosition.behaviour.setScreenWidth(800);
        
        addMouseListener(this, true);
    }
    
    void mouseDown(const MouseEvent& e) override {
        position = e.getPosition();
        animatedPosition.beginDrag();
    }

    void mouseDrag(const MouseEvent& e) override {
        //log->writeToLog("Drag: " + String(e.getPosition().getX()) + " val: " + String(e.getPosition().getX() - position.getX()));
        float val = e.getPosition().getX() - position.getX();
        //auto val = e.getPosition().getX() - animatedPosition.getPosition();
        animatedPosition.drag(val);
    }

    void mouseUp(const MouseEvent& e) override {
        animatedPosition.endDrag();
    }
    
    
    
    void positionChanged(AnimatedPosition<AnimatedPositionBehaviours::SnapToPageWithMomentum>& animatedPos, double newPos) override {
        auto currentScreen = animatedPos.behaviour.getScreen().getCurrentScreen();
        auto relativePosition = -newPos * currentScreen;
        screen1.setBounds(relativePosition, screen1.getY(), screen1.getWidth(), screen1.getHeight());
        screen2.setBounds(relativePosition + 800, screen2.getY(), screen2.getWidth(), screen2.getHeight());
        screen3.setBounds(relativePosition + 1600, screen3.getY(), screen3.getWidth(), screen3.getHeight());
    }
    
    void paint(Graphics& g) override {
        g.setColour(Colours::pink);
        g.fillAll();
    }
    
    void resized() override {
        screen1.setBounds(getLocalBounds().removeFromTop(500));
        screen2.setBounds(getWidth(), 0, getWidth(), getHeight() - 100);
        screen3.setBounds(getWidth()*2, 0, getWidth(), getHeight() - 100);
    }
    
private:
    GlobalEffectConfigurationView screen2;
    BlackScreen screen1;
    BlackScreen screen3;
    AnimatedPosition<AnimatedPositionBehaviours::SnapToPageWithMomentum> animatedPosition;
    Point<int> position;
    Logger* log;
};
