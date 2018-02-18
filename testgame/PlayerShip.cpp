//
//  PlayerShip.cpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "PlayerShip.hpp"


void PlayerShip::update()
{
   // printf("hi");
    if(key[KEY_UP] && y >= 4.0) {
        
        move(0,-4);
    }
    
    if(key[KEY_DOWN] && y <= G_SCREEN_H - h - 4.0) {
        
        move(0,4);
    }
    
    if(key[KEY_LEFT] && x >= 4.0) {
        
        move(-4,0);
    }
    
    if(key[KEY_RIGHT] && x <= G_SCREEN_W - w - 4.0) {
        
        move(4,0);
    }
    bulletGen->update();
    //fire();
}

void PlayerShip::fire()
{
     bulletGen->generateBullet(x+this->h, y+this->w/4, 10, 0, getID());
}


void PlayerShip::collide(gameobject *go)
{
    if (go->getID() < 0)//hack hihihihi
    {
        hp+=10;
    }
    else if (go->getID() != getID())
    {
        hp-=10;
        if (hp<=0)
            markForDeath = true;
    }
}


