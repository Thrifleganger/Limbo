/*
  ==============================================================================

    ReverbSliderGroupView.cpp
    Created: 1 Sep 2018 12:36:22pm
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

class ReverbSliderGroupView : public Component, public AbstractViewConfigurer {
    
public:
    
    ReverbSliderGroupView() : AbstractViewConfigurer(&orienter, &configurer) {
        
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
    
    ~ReverbSliderGroupView() {}
    
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
        sliderModels.add(SliderModel().withName("reverbDecayTime").withRangeLowerLimit(0.05).withRangeUpperLimit(5.0));
        sliderModels.add(SliderModel().withName("shimmer").withRangeLowerLimit(0.0).withRangeUpperLimit(0.5));
        sliderModels.add(SliderModel().withName("playbackSend").withRangeLowerLimit(0.0).withRangeUpperLimit(1.0));
        sliderModels.add(SliderModel().withName("effectSend").withRangeLowerLimit(0.0).withRangeUpperLimit(1.0));
    }

    void instantiateLabelModel() {
        labelModels.add(LabelModel().withName("reverbDecayTime").withText("Decay Time"));
        labelModels.add(LabelModel().withName("shimmer").withText("Shimmer"));
        labelModels.add(LabelModel().withName("playbackSend").withText("Playback Send"));
        labelModels.add(LabelModel().withName("effectSend").withText("Effect Send"));
    }
};
