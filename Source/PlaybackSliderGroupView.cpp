/*
  ==============================================================================

    PlaybackSliderGroupView.cpp
    Created: 31 Aug 2018 9:20:41pm
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

class PlaybackSliderGroupView : public Component, public AbstractViewConfigurer {
    
public:
    
    PlaybackSliderGroupView() : AbstractViewConfigurer(&orienter, &configurer) {
        
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
    
    ~PlaybackSliderGroupView() {}
    
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
        sliderModels.add(SliderModel().withName("playbackGain").withRangeLowerLimit(0.0).withRangeUpperLimit(1.0));
        sliderModels.add(SliderModel().withName("playbackRate").withRangeLowerLimit(0.0).withRangeUpperLimit(1.0));
        sliderModels.add(SliderModel().withName("playbackChangeTime").withRangeLowerLimit(1.0).withRangeUpperLimit(10.0));
        sliderModels.add(SliderModel().withName("rmsThreshold").withRangeLowerLimit(0.0).withRangeUpperLimit(10.0));
    }
    
    void instantiateLabelModel() {
        labelModels.add(LabelModel().withName("playbackGain").withText("Gain"));
        labelModels.add(LabelModel().withName("playbackRate").withText("ManualRate"));
        labelModels.add(LabelModel().withName("playbackChangeTime").withText("Change rate"));
        labelModels.add(LabelModel().withName("rmsThreshold").withText("Level"));
    }
};
