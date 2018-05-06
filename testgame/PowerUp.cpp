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
    if (go->getID() == GAME_OBJECT_ID_PLAYERSHIP)
    {
        //     std::cout << "boom";
        markForDeath = true;
    }
}
void PowerUp::update()
{
    location = Add2DV(location, velocity);
    int x = location.x;
    int y = location.y;
    
    if (x < 0 || x > G_SCREEN_W)
        velocity.x *= -1;
    if (y < G_SCREEN_CEILING || y > G_SCREEN_H)
        velocity.y *= -1;
    
    timeToLive--;
    if (timeToLive <= 0)
        markForDeath = true;
}
void PowerUp::init()
{
    
}
void PowerUp::draw(ALLEGRO_DISPLAY *display)
{
    int x = location.x;
    int y = location.y;
    
    if (timeToLive > 100 || timeToLive%10 < 5)
        al_draw_bitmap(b, x, y, 0);
}

void PowerUp::destroy()
{
    G_Collider->remove(this);
    this->~PowerUp();
    
}