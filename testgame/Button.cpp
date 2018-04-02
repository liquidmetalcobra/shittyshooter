//
//  Button.cpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "Button.hpp"
void Button::update()
{
    
    
}
void Button::init()
{
    
}
void Button::draw()
{
    float alpha = 0.5f;
    ALLEGRO_COLOR color = al_map_rgba_f(1.0*alpha, 0.4*alpha, 0.6*alpha, alpha); // <-- correct
    //ALLEGRO_COLOR color = al_map_rgba_f(1.0, 0.4, 0.6, alpha); // <--no longer correct
   
    
   
    
    al_draw_bitmap(background, location.x, location.y, 0);
    al_draw_bitmap(b,location.x, location.y, 0);
    al_set_target_bitmap(b);
     al_draw_text(font, color, 10, 10, NULL, "This is transparent text.");
    
    //al_draw_scaled_bitmap(b, 0, 0, w, h, x, y, w, h, 0);
}
void Button::destroy()
{
    
}
bool Button::isButtonClicked(int mbX, int mbY)
{
    int x = location.x;
    int y = location.y;
    int w = size.x;
    int h = size.y;
    if (mbX < x + w && mbX > x && mbY < y + h && mbY > y)
    {
        //buttonPressed();
        printf("button Pressed");
        return true;
        
    }
    return false;
    
}