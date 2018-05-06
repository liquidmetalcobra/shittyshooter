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
    HealthBar(Vector_2D location, Vector_2D size, gameobject * go, int * hp, int *hmp) : UIElement(location,size,go)
    {
        healthPointer = hp;
        healthmaxPointer = hmp;
        
        std::string fontName = G_FONT_LOCATION + "8bit.ttf";
        //buttonPressed = (void *)callBack;
        font = al_load_ttf_font(fontName.c_str(),30,0 );
        float alpha = 1.0f;
        color = al_map_rgba_f(1.0*alpha, 1.0*alpha, 1.0*alpha, alpha); // <-- correct
        
        
        
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
    void draw(ALLEGRO_DISPLAY *display);
    void destroy();
    
    
protected:
    
private:
    float displayhealth;
    float healthmax;
    int *healthPointer;
    int *healthmaxPointer;
    
    ALLEGRO_FONT *font;
    ALLEGRO_COLOR color;
};