//
//  TextBox.hpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#pragma once


#include <iostream>
#include "UIElement.hpp"
#include "Button.hpp"

class TextBox : public UIElement
{
    
public:
    TextBox(Vector_2D loc, Vector_2D size, std::string t, ALLEGRO_COLOR *c) : UIElement(loc,size,NULL)
    {
        //TextBoxPressed = (void *)callBack;
       
        std::string fontName = G_FONT_LOCATION + "8bit.ttf";
        //buttonPressed = (void *)callBack;
        font = al_load_ttf_font(fontName.c_str(),30,0 );
        
        color = c ? *c : al_map_rgb(0, 0, 0);
        
        text = t;
        
        background = al_create_bitmap(size.x, size.y);
        al_set_target_bitmap(background);
        al_clear_to_color(al_map_rgb(255, 255, 255));
    }
    ~TextBox()
    {
        
        al_destroy_bitmap(background);
    }
    void update();
    void init();
    void draw(ALLEGRO_DISPLAY *display);
    void destroy();
    
    
protected:
    

    
    std::string text;
    ALLEGRO_COLOR c;
    ALLEGRO_FONT *font;
private:    
    
    
    
};