/*
  ==============================================================================

    SliderModel.h
    Created: 31 Aug 2018 9:18:07pm
    Author:  Akash Murthy

  ==============================================================================
*/
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "ComponentModel.h"

class SliderModel : public ComponentModel {

public:
    
    SliderModel() {}
    
    SliderModel(String name, double lowerRange, double upperRange) :
        name(name), rangeLowerLimit(lowerRange), rangeUpperLimit(upperRange)
    {}
    
    String getName() const { return name; }
    double getRangeLowerLimit() const { return rangeLowerLimit; }
    double getRangeUpperLimit() const { return rangeUpperLimit; }
    
    SliderModel& withName(const String& name) {
        this->name = name;
        return *this;
    }
    
    SliderModel& withRangeLowerLimit(const double& rangeLowerLimit) {
        this->rangeLowerLimit = rangeLowerLimit;
        return *this;
    }
    
    SliderModel& withRangeUpperLimit(const double& rangeUpperLimit) {
        this->rangeUpperLimit = rangeUpperLimit;
        return *this;
    }
    
private:
    
    String name;
    double rangeLowerLimit;
    double rangeUpperLimit;
};
