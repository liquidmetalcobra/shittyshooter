//
//  IntTextBox.cpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "IntTextBox.hpp"
void IntTextBox::update()
{
    
    
}
void IntTextBox::init()
{
    
}
void IntTextBox::draw(ALLEGRO_DISPLAY *display)
{
    int x = location.x;
    int y = location.y;
    al_draw_bitmap(background, x, y, 0);
    
    std::string finalText = text + itos(*num);
    
    al_draw_text(font, color, x, y, NULL, finalText.c_str());
    
    // al_draw_bitmap(b,location.x, location.y, 0);
    //al_draw_scaled_bitmap(b, 0, 0, w, h, x, y, w, h, 0);
}
void IntTextBox::destroy()
{
    
}
