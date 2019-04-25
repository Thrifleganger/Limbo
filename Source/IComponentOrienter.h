/*
  ==============================================================================

    IComponentOrienter.cpp
    Created: 2 Sep 2018 9:51:43am
    Author:  Akash Murthy

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class IComponentOrienter {
   
public:
    virtual ~IComponentOrienter() {}
    virtual void alignAndOrient(const OwnedArray<FlexItem>&, const Rectangle<int>&) = 0;
};
