//
//  bullet.cpp
//  testgame
//
//  Created by Sasha Han on 10/14/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "PowerUp.hpp"
void PowerUp::collide(gameobject *go)
{
    if (go->getID() != getID())
    {
        //     std::cout << "boom";
        markForDeath = true;
    }
}
void PowerUp::update()
{
    x+=vel[0];
    y+=vel[1];
    if (x < 0 || x > G_SCREEN_W)
        vel[0] *= -1;
    if (y < 0 || y > G_SCREEN_H)
        vel[1] *= -1;
    
    timeToLive--;
    if (timeToLive <= 0)
        markForDeath = true;
}
void PowerUp::init()
{
    
}
void PowerUp::draw()
{
    if (timeToLive > 100 || timeToLive%10 < 5)
        al_draw_bitmap(b, x, y, 0);
}

void PowerUp::destroy()
{
    c->remove(this);
    this->~PowerUp();
    
}