/*
  ==============================================================================

    LabelModel.h
    Created: 3 Sep 2018 11:04:51pm
    Author:  Akash Murthy

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "ComponentModel.h"

class LabelModel : public ComponentModel {
    
public:
    
    LabelModel() {}
    
    String getName() const { return name; }
    String getText() const { return text; }
    
    LabelModel& withName(const String& name) {
        this->name = name;
        return *this;
    }
    
    LabelModel& withText(const String& text) {
        this->text = text;
        return *this;
    }
    
private:
    
    String name;
    String text;
};
