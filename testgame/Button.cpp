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
    al_draw_bitmap(background, location.x, location.y, 0);
    al_draw_bitmap(b,location.x, location.y, 0);
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