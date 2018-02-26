//
//  HealthBar.hpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#pragma once


#include <iostream>
#include "UIElement.hpp"


class HealthBar : public UIElement
{
    
public:
    HealthBar(Vector_2D location, Vector_2D size, gameobject * go, int * hp) : UIElement(location,size,go)
    {
        healthPointer = hp;
        
        
        b = al_create_bitmap(size.x, size.y);
        al_set_target_bitmap(b);
        al_clear_to_color(al_map_rgb(255, 0, 0));
        
        
        background = al_create_bitmap(size.x, size.y);
        al_set_target_bitmap(background);
        al_clear_to_color(al_map_rgb(255, 255, 255));
    }
    ~HealthBar()
    {
        al_destroy_bitmap(b);
        al_destroy_bitmap(background);
    }
    void update();
    void init();
    void draw();
    void destroy();
    
    
protected:
    
private:
    float displayhealth;
    int *healthPointer;
    
    
    
};