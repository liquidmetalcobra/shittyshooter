//
//  Window.cpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "Window.hpp"
void Window::update()
{
    
    
}
void Window::init()
{
    
}
void Window::draw(ALLEGRO_DISPLAY *display)
{
    al_draw_bitmap(background, location.x, location.y, 0);
   // al_draw_bitmap(b,location.x, location.y, 0);
    //al_draw_scaled_bitmap(b, 0, 0, w, h, x, y, w, h, 0);
}
void Window::destroy()
{
    
}
bool Window::isWindowClicked(int mbX, int mbY)
{
    int x = location.x;
    int y = location.y;
    int w = size.x;
    int h = size.y;
    if (mbX < x + w && mbX > x && mbY < y + h && mbY > y)
    {
        //WindowPressed();
        printf("Window Pressed");
        return true;
        
    }
    return false;
    
}