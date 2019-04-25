/*
  ==============================================================================

    MasterToggleButtonConfigurer.cpp
    Created: 9 Sep 2018 3:17:42pm
    Author:  Akash Murthy

  ==============================================================================
*/

#include "IComponentConfigurer.h"
#include "SliderModel.h"
#include "ComponentType.h"

class MasterToggleButtonConfigurer : public IComponentConfigurer {
    
public:
    
    MasterToggleButtonConfigurer() {}
    
    void configure(Component* component, ComponentModel* componentModel) override {
        
        auto* button = static_cast<ToggleButton*>(component);
        auto* model = static_cast<SliderModel*>(componentModel);
        
    }
    
private:
    
    bool isOfType(const int& typeToMatch, const ComponentType& predefinedType) {
        return typeToMatch == static_cast<int>(predefinedType);
    }
};
