//
//  HelperShip.cpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "HelperShip.hpp"


void HelperShip::update()
{
    if (count > firerate)
    {
        bulletGen->generateBullet(location, Vector_2D(10, 0), getID());
        count = 0;
    }
    else
    {
        count++;
    }
    bulletGen->update();}

void HelperShip::fire()
{
    
}


void HelperShip::collide(gameobject *go)
{
    if (go->getID() != getID())
    {
        hp-=10;
        if (hp<=0)
            markForDeath = true;
    }
}


