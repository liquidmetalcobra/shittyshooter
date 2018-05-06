//
//  Button.hpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#pragma once


#include <iostream>
#include "UIElement.hpp"


class Button : public UIElement
{
    
public:
    Button(Vector_2D loc, Vector_2D size, std::string *text, std::function<void(void)> callBack) : UIElement(loc,size,NULL)
    {
        std::string fontName = G_FONT_LOCATION + "8bit.ttf";
        buttonPressed = callBack;
        font = al_load_ttf_font(fontName.c_str(),15,0 );
        if (!font){
            fprintf(stderr, "Could not load 'pirulen.ttf'.\n");
            
        }
        
        b = al_create_bitmap(size.x, size.y);
        al_set_target_bitmap(b);
        al_clear_to_color(al_map_rgb(255, 255, 255));
   
        float alpha = 1.0f;
        ALLEGRO_COLOR color = al_map_rgba_f(1.0*alpha, 0.4*alpha, 0.6*alpha, alpha); // <-- correct
        if (text != NULL)
            al_draw_text(font, color, 10, 10, NULL, text->c_str());
        
        
        
        background = al_create_bitmap(size.x, size.y);
        al_set_target_bitmap(background);
        al_clear_to_color(al_map_rgb(125, 125, 125));
        
        
        
        
    }
    ~Button()
    {
        al_destroy_bitmap(b);
        al_destroy_bitmap(background);
    }
    void update();
    void init();
    void draw(ALLEGRO_DISPLAY *display);
    void destroy();
    bool isButtonClicked(int mbX, int mbY);
    
    
protected:
    
private:
    
    std::function<void(void)> buttonPressed;
    ALLEGRO_FONT *font;
    
    
    
};