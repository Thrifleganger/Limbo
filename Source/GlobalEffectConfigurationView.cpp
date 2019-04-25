/*
  ==============================================================================

    GlobalEffectConfigurationView.cpp
    Created: 1 Sep 2018 12:59:55pm
    Author:  Akash Murthy

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PlaybackSliderGroupView.cpp"
#include "DelaySliderGroupView.cpp"
#include "DroneSliderGroupView.cpp"
#include "GlitchSliderGroupView.cpp"
#include "ReverbSliderGroupView.cpp"

class GlobalEffectConfigurationView : public Component {
    
public:
    
    GlobalEffectConfigurationView() {
        addAndMakeVisible(playbackView);
        addAndMakeVisible(delayView);
        addAndMakeVisible(droneView);
        addAndMakeVisible(glitchView);
        addAndMakeVisible(reverbView);
        
        background = Drawable::createFromImageData(BinaryData::LimboPage3_png, BinaryData::LimboPage3_pngSize);
    }
    
    ~GlobalEffectConfigurationView() {}
    
    void paint(Graphics& g) override {
        if (background != 0) {
            background->drawWithin(g, getLocalBounds().toFloat(), RectanglePlacement::Flags::stretchToFit, 1.0f);
        }
    }
    
    void resized() override {
        auto boundary = getLocalBounds();
        auto subContainerWidth = getWidth() / 5.0f;
        boundary.removeFromTop(getHeight() * 0.1f);
        boundary.removeFromBottom(getHeight() * 0.1f);
        
        playbackView.setBounds(boundary.removeFromLeft(subContainerWidth));
        delayView.setBounds(boundary.removeFromLeft(subContainerWidth));
        droneView.setBounds(boundary.removeFromLeft(subContainerWidth));
        glitchView.setBounds(boundary.removeFromLeft(subContainerWidth));
        reverbView.setBounds(boundary);
        
        playbackView.setPaintingIsUnclipped(true);
        delayView.setPaintingIsUnclipped(true);
        droneView.setPaintingIsUnclipped(true);
        glitchView.setPaintingIsUnclipped(true);
        reverbView.setPaintingIsUnclipped(true);
    }
    
private:
    PlaybackSliderGroupView playbackView;
    DelaySliderGroupView delayView;
    DroneSliderGroupView droneView;
    GlitchSliderGroupView glitchView;
    ReverbSliderGroupView reverbView;
    
    ScopedPointer<Drawable> background;
};
