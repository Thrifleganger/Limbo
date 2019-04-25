/*
  ==============================================================================

    GlitchSliderGroupView.cpp
    Created: 1 Sep 2018 12:36:11pm
    Author:  Akash Murthy

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SliderModel.h"
#include "LabelModel.h"
#include "AbstractViewConfigurer.h"
#include "SliderAndLabelConfigurer.h"
#include "SliderAndLabelInterleavedColumnAlignedOrienter.h"

class GlitchSliderGroupView : public Component,
                              public AbstractViewConfigurer
{
    
public:
    
    GlitchSliderGroupView() : AbstractViewConfigurer(&orienter, &configurer) {
        
        instantiateSliderModel();
        instantiateLabelModel();
        assert(sliderModels.size() == labelModels.size());
        
        for (auto model : labelModels) {
            auto* label = new Label();
            label->getProperties().set("type", static_cast<int>(ComponentType::LABEL));
            configureComponent(label, &model);
            addAndMakeVisible(labels.add(label));
        }
        for (auto model : sliderModels) {
            auto* slider = new Slider();
            slider->getProperties().set("type", static_cast<int>(ComponentType::SLIDER));
            configureComponent(slider, &model);
            addAndMakeVisible(sliders.add(slider));
        }
        for (int i = 0; i < sliders.size(); i++) {
            flexItems.add(new FlexItem(static_cast<FlexItem>(*sliders[i])));
            flexItems.add(new FlexItem(static_cast<FlexItem>(*labels[i])));
        }
    }
    
    ~GlitchSliderGroupView() {}
    
    void resized() override {
        orientComponents(flexItems, getLocalBounds().removeFromTop(getLocalBounds().getHeight() * 3.0 / 4.0));
    }
    
private:
    
    OwnedArray<Slider> sliders {};
    OwnedArray<Label> labels {};
    OwnedArray<FlexItem> flexItems {};
    
    Array<SliderModel> sliderModels {};
    Array<LabelModel> labelModels {};
    SliderAndLabelConfigurer configurer {};
    SliderAndLabelInterleavedColumnAlignedOrienter orienter {};
    
    void instantiateSliderModel() {
        sliderModels.add(SliderModel().withName("glitchAmount").withRangeLowerLimit(0.0).withRangeUpperLimit(1.0));
        sliderModels.add(SliderModel().withName("glitchRate").withRangeLowerLimit(0.01).withRangeUpperLimit(10.0));
        sliderModels.add(SliderModel().withName("glitchMix").withRangeLowerLimit(0.0).withRangeUpperLimit(2.0));
    }
    
    void instantiateLabelModel() {
        labelModels.add(LabelModel().withName("glitchAmount").withText("Amount"));
        labelModels.add(LabelModel().withName("glitchRate").withText("Rate"));
        labelModels.add(LabelModel().withName("glitchMix").withText("Mix"));
    }
};
