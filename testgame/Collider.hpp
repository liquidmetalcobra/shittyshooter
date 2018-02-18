//
//  Collider.hpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//
#pragma once

#include <iostream>
#include <vector>
#include "globals.h"
#include "gameobject.hpp"

enum collisionClasses { COLLISION_CLASS_SHIP, COLLISION_CLASS_BULLET, COLLISION_CLASS_POWERUP};

class collider
{
public:
    collider()
    {
    };
    ~collider(){
        ships.clear();
        bullets.clear();
        powerups.clear();
    };
    
    void update();
    void add(gameobject* a, collisionClasses id);
    void remove(gameobject * r);
    long getSize(collisionClasses c);
    void empty(collisionClasses c);
private:
    
    bool checkCollision(gameobject* a, gameobject* b);
    std::vector<gameobject*> ships;
    std::vector<gameobject*> bullets;
    std::vector<gameobject*> powerups;
    
};