//
//  bullet.cpp
//  testgame
//
//  Created by Sasha Han on 10/14/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "bullet.hpp"
void bullet::collide(gameobject *go)
{
    if (go->getID() != getID())
    {
   //     std::cout << "boom";
        markForDeath = true;
    }
}
void bullet::update()
{
    x+=vel[0];
    y+=vel[1];
    if (x < 0 || x > G_SCREEN_W || y < 0 || y > G_SCREEN_H)
        markForDeath = true;
}
void bullet::init()
{
    
}
void bullet::draw()
{
    al_draw_bitmap(b, x, y, 0);
}

void bullet::destroy()
{
    //G_Handler->remove(this);
    //G_Collider->remove(this);
    this->~bullet();
    
}