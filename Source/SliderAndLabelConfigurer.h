/*
  ==============================================================================

    SliderConfigurer.cpp
    Created: 2 Sep 2018 10:24:00am
    Author:  Akash Murthy

  ==============================================================================
*/

#pragma once

#include "IComponentConfigurer.h"
#include "SliderModel.h"
#include "LabelModel.h"
#include "ComponentType.h"

class SliderAndLabelConfigurer : public IComponentConfigurer {
  
public:
    
    SliderAndLabelConfigurer() {}
    
    void configure(Component* component, ComponentModel* componentModel) override {
        
        auto type = static_cast<int>(component->getProperties()["type"]);
        if (isOfType(type, ComponentType::SLIDER)) {
            auto* slider = static_cast<Slider*>(component);
            auto* model = static_cast<SliderModel*>(componentModel);
            slider->setName(model->getName());
            slider->setRange(model->getRangeLowerLimit(), model->getRangeUpperLimit());
            slider->setSliderStyle(Slider::RotaryVerticalDrag);
            slider->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
        } else if(isOfType(type, ComponentType::LABEL)) {
            auto* label = static_cast<Label*>(component);
            auto* model = static_cast<LabelModel*>(componentModel);
            label->setName(model->getName());
            label->setText(model->getText(), dontSendNotification);
            label->setJustificationType(Justification::horizontallyCentred);
        }
    }
    
private:
    
    bool isOfType(const int& typeToMatch, const ComponentType& predefinedType) {
        return typeToMatch == static_cast<int>(predefinedType);
    }
};
