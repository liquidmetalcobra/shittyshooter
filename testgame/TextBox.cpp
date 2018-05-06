//
//  TextBox.cpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "TextBox.hpp"
void TextBox::update()
{
    
    
}
void TextBox::init()
{
    
}
void TextBox::draw(ALLEGRO_DISPLAY *display)
{
    int x = location.x;
    int y = location.y;
    al_draw_bitmap(background, x, y, 0);
    al_draw_text(font, color, x, y, NULL, text.c_str());
    
    // al_draw_bitmap(b,location.x, location.y, 0);
    //al_draw_scaled_bitmap(b, 0, 0, w, h, x, y, w, h, 0);
}
void TextBox::destroy()
{
    
}
