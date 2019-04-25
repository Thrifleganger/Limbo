/*
  ==============================================================================

    MainToggleButtonView.cpp
    Created: 31 Aug 2018 7:15:56pm
    Author:  Akash Murthy

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class MainToggleButtonView : public Component {
    
public:
    
    MainToggleButtonView() {
        for (auto name : names) {
            ToggleButton* button = new ToggleButton();
            button->setName(name);
            button->setPaintingIsUnclipped(true);
            addAndMakeVisible(buttons.add(button));
        }
    }
    
    ~MainToggleButtonView() {}
    
    void paint(Graphics& g) override {
        g.fillAll(Colours::white);
    }
    
    void resized() override {
        FlexBox toggleButtonBox;
        toggleButtonBox.flexDirection = FlexBox::Direction::row;
        toggleButtonBox.flexWrap = FlexBox::Wrap::noWrap;
        //toggleButtonBox.justifyContent = FlexBox::JustifyContent::spaceAround;
        //toggleButtonBox.alignItems = FlexBox::AlignItems::center;
        
        for (auto* b : buttons) {
            toggleButtonBox.items.add(static_cast<FlexItem>(*b)
                  .withMinHeight(getLocalBounds().getHeight())
                  .withMinWidth(getLocalBounds().getWidth() / 5.0f)
                  .withFlex(1)
            );
        }
        toggleButtonBox.performLayout(getLocalBounds().toFloat());
    }
    
private:
    OwnedArray<ToggleButton> buttons {};
    String names[5] {"Playback", "Delay", "Drone", "Glitch", "Reverb"};
};
