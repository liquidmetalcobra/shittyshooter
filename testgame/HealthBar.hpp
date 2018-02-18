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
    HealthBar(int iX, int iY, int iW, int iH, gameobject * go, int * hp) : UIElement(iX,iY,iW,iH,go)
    {
        healthPointer = hp;
        
        
        b = al_create_bitmap(w, h);
        al_set_target_bitmap(b);
        al_clear_to_color(al_map_rgb(255, 0, 0));
        
        
        background = al_create_bitmap(w, h);
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