/*
  ==============================================================================

    SliderAndLabelInterleavedColumnAlignedOrienter.cpp
    Created: 2 Sep 2018 10:13:40am
    Author:  Akash Murthy

  ==============================================================================
*/

#pragma once

#include "IComponentOrienter.h"
#include "ComponentType.h"

class SliderAndLabelInterleavedColumnAlignedOrienter : public IComponentOrienter {
    
public:
    
    SliderAndLabelInterleavedColumnAlignedOrienter() {}
    
    void alignAndOrient(const OwnedArray<FlexItem>& flexItems, const Rectangle<int>& localBounds) override {
        
        FlexBox sliderBox;
        sliderBox.flexDirection = FlexBox::Direction::column;
        sliderBox.justifyContent = FlexBox::JustifyContent::flexStart;
        sliderBox.flexWrap = FlexBox::Wrap::noWrap;
        
        FlexBox labelBox;
        labelBox.flexDirection = FlexBox::Direction::column;
        labelBox.justifyContent = FlexBox::JustifyContent::flexStart;
        
        auto overflowVariable = localBounds.getHeight() / (flexItems.size() / 2);
        
        for (auto* flexItem : flexItems) {
            auto type = static_cast<int>(flexItem->associatedComponent->getProperties()["type"]);
            if (isOfType(type, ComponentType::SLIDER)) {
                sliderBox.items.add((*flexItem)
                    .withMinHeight(30.0f)
                                    .withMinWidth(localBounds.getWidth()).withFlex(0.5)
                                    
                );
            } else if (isOfType(type, ComponentType::LABEL)) {
                labelBox.items.add((*flexItem)
                    .withMinHeight(30.0f)
                    .withMinWidth(localBounds.getWidth())
                    .withMargin(FlexItem::Margin(0, 0, - overflowVariable, 0))
                    .withFlex(0.5)
                    
                );
            }
        }
        labelBox.performLayout(localBounds.toFloat());
        sliderBox.performLayout(localBounds.toFloat());
    }
    
private:
    
    bool isOfType(const int& typeToMatch, const ComponentType& predefinedType) {
        return typeToMatch == static_cast<int>(predefinedType);
    }
};
