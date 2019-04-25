/*
  ==============================================================================

    IComponentConfigurer.cpp
    Created: 2 Sep 2018 10:03:13am
    Author:  Akash Murthy

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ComponentModel.h"

class IComponentConfigurer {
  
public:
    virtual ~IComponentConfigurer() {}
    virtual void configure(Component*, ComponentModel*) = 0;
};
