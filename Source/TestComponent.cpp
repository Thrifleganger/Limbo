/*
  ==============================================================================

    TestComponent.cpp
    Created: 30 Aug 2018 9:03:06pm
    Author:  Akash Murthy

  ==============================================================================
*/
#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class TestComponent : public Component {
public: 
    TestComponent() {
        addAndMakeVisible(b1);
        addAndMakeVisible(b2);
        addAndMakeVisible(b3);
        setSize(400, 400);
    }
    void paint(Graphics& g) override {
        g.fillAll (Colours::black);
        g.setFont(20.0f);
    }
    void resized() override {
        auto r = getLocalBounds();
        b1.setBounds(r.removeFromTop(100));
        b2.setBounds(r.removeFromLeft(200));
        b3.setBounds(r);
    }
    TextButton b1{"1"}, b2{"2"}, b3{"3"};
};
