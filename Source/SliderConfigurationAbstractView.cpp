/*
  ==============================================================================

    SliderConfigurationAbstractView.cpp
    Created: 1 Sep 2018 12:24:12pm
    Author:  Akash Murthy

  ==============================================================================
*/

#pragma once

#include "SliderModel.h"
#include "../JuceLibraryCode/JuceHeader.h"

class SliderConfigurationAbstractView {
    
public:
    
    SliderConfigurationAbstractView() {}
    virtual ~SliderConfigurationAbstractView() {}
    
    virtual void alignSlidersWithFlexBox(const OwnedArray<Slider>& sliders, const Rectangle<int>& localBounds) {
        FlexBox sliderBox;
        sliderBox.flexDirection = FlexBox::Direction::column;
        sliderBox.justifyContent = FlexBox::JustifyContent::flexStart;
        sliderBox.alignContent = FlexBox::AlignContent::flexStart;
        sliderBox.alignItems = FlexBox::AlignItems::flexStart;
        
        for (auto* slider : sliders) {
            sliderBox.items.add(static_cast<FlexItem>(*slider)
                .withMinHeight(30.0f)
                .withMinWidth(localBounds.getWidth())
                .withMargin(FlexItem::Margin(0, 0, 10.0f, 0)).withFlex(0.5f)
            );
        }
        sliderBox.performLayout(localBounds.toFloat());
    }
    
    virtual void configureSliderWithDefaults(Slider& slider, const SliderModel& model) {
        slider.setName(model.getName());
        slider.setRange(model.getRangeLowerLimit(), model.getRangeUpperLimit());
        slider.setSliderStyle(Slider::RotaryVerticalDrag);
        slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    }
};
