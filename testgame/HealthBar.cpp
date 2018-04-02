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
}
void HealthBar::init()
{
    
}
void HealthBar::draw()
{
    int x = getAbsoluteLocation().x;
    int y = getAbsoluteLocation().y;
    int w = size.x;
    int h = size.y;
    al_draw_bitmap(background, x, y, 0);
    al_draw_scaled_bitmap(b, 0, 0, w, h, x, y, w*(displayhealth/100), h, 0);
}
void HealthBar::destroy()
{
    
}