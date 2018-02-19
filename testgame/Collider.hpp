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


#define G_Collider collider::instance()



class collider
{

    static collider *col;
    collider()
    {
    };
    ~collider(){
        ships.clear();
        bullets.clear();
        powerups.clear();
    };
    
public:
    static collider *instance()
    {
        if (!col)
            col = new collider();
        return col;
    }
    
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