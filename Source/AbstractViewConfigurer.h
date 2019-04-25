/*
  ==============================================================================

    AbstractViewConfigurer.h
    Created: 2 Sep 2018 12:04:10pm
    Author:  Akash Murthy

  ==============================================================================
*/

#pragma once
#include "IComponentOrienter.h"
#include "IComponentConfigurer.h"

class AbstractViewConfigurer {
    
public:
    AbstractViewConfigurer(IComponentOrienter* a, IComponentConfigurer* c) : orienter(a), configurer(c) {}
    virtual ~AbstractViewConfigurer() = default;
    
    virtual void configureComponent(Component* component, ComponentModel* model) {
        configurer->configure(component, model);
    }
    
    virtual void orientComponents(const OwnedArray<FlexItem>& items, const Rectangle<int>& bounds) {
        orienter->alignAndOrient(items, bounds);
    }
    
private:
    IComponentOrienter* orienter;
    IComponentConfigurer* configurer;
};
