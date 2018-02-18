//
//  GameObjectHandler.hpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//
#pragma once

#include <iostream>
#include "globals.h"
#include "gameobject.hpp"
#include <vector>


class GameObjectHandler
{
    
public:
    GameObjectHandler()
    {
        
    }
    ~GameObjectHandler()
    {
       // objects.clear();
    }
    
    void add(gameobject* go);
    void remove(gameobject * go);
    void update();
    void draw();
    void empty() { objects.clear(); }
    long getSize() { return objects.size(); }
    
private:
    std::vector<gameobject*> objects;
    
    
};