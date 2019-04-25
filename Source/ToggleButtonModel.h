/*
  ==============================================================================

    ToggleButtonModel.h
    Created: 3 Apr 2019 6:53:09am
    Author:  Akash Murthy

  ==============================================================================
*/

#pragma once

#include "ComponentModel.h"

class ToggleButtonModel : public ComponentModel {
    
public:
    
    ToggleButtonModel& withName(const String name) {
        this->name = name;
        return *this;
    }
    
    ToggleButtonModel& setEnabled(const bool isEnabled) {
        this->isEnabled = isEnabled;
        return *this;
    }
    
    String getName() const {
        return name;
    }
    
    bool isEnabled() const {
        return isEnabled;
    }
    
private:
    String name;
    bool isEnabled;
};
