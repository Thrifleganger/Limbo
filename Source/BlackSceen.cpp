/*
  ==============================================================================

    BlackSceen.cpp
    Created: 1 Sep 2018 7:11:32pm
    Author:  Akash Murthy

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class BlackScreen : public Component {
    
public:
    
    BlackScreen() {}
    
    void paint(Graphics& g) override {
        g.setColour(Colours::black);
        g.fillAll();
    }
};
