/*
  ==============================================================================

    DelaySliderGroupView.cpp
    Created: 1 Sep 2018 12:35:44pm
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

class DelaySliderGroupView : public Component, public AbstractViewConfigurer {
    
public:
    
    DelaySliderGroupView() : AbstractViewConfigurer(&orienter, &configurer) {
        
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
    
    ~DelaySliderGroupView() {}
    
    void resized() override {
        orientComponents(flexItems, getLocalBounds());
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
        sliderModels.add(SliderModel().withName("delayTime").withRangeLowerLimit(0.0).withRangeUpperLimit(5.0));
        sliderModels.add(SliderModel().withName("delayVariance").withRangeLowerLimit(0.0).withRangeUpperLimit(1.0));
        sliderModels.add(SliderModel().withName("delayFeedback").withRangeLowerLimit(0.0).withRangeUpperLimit(1.0));
        sliderModels.add(SliderModel().withName("delayMix").withRangeLowerLimit(0.0).withRangeUpperLimit(1.0));
    }
    
    void instantiateLabelModel() {
        labelModels.add(LabelModel().withName("delayTime").withText("Time"));
        labelModels.add(LabelModel().withName("delayVariance").withText("Variance"));
        labelModels.add(LabelModel().withName("delayFeedback").withText("Feedback"));
        labelModels.add(LabelModel().withName("delayMix").withText("Mix"));
    }
};
