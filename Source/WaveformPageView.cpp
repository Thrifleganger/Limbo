/*
  ==============================================================================

    WaveformPageView.cpp
    Created: 25 Apr 2019 7:29:43pm
    Author:  Akash Murthy

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "MasterEffectToggleButtonView.cpp"

class WaveformPageView : public Component {

public:
    
    WaveformPageView() {
        //addAndMakeVisible(buttonView);
    }
    
    void resized() override {
        //buttonView.setBounds(getLocalBounds());
    }
    
private:
    //MasterEffectToggleButtonView buttonView;
};
