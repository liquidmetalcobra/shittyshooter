//
//  HealthBar.cpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "HealthBar.hpp"
void HealthBar::update()
{
    
    displayhealth = *healthPointer;
    healthmax = *healthmaxPointer;
    
}
void HealthBar::init()
{
    
}
void HealthBar::draw(ALLEGRO_DISPLAY *display)
{
    int x = getAbsoluteLocation().x;
    int y = getAbsoluteLocation().y;
    int w = size.x;
    int h = size.y;
    al_draw_bitmap(background, x, y, 0);
    al_draw_scaled_bitmap(b, 0, 0, w, h, x, y, w*(displayhealth/healthmax), h, 0);
    
    std::string health = itos(displayhealth) + "/" + itos(healthmax);
    
    al_draw_text(font, color, x, y, NULL, health.c_str());
    
}
void HealthBar::destroy()
{
    
}