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
#include "Collider.hpp"
#include <vector>

#define G_Handler GameObjectHandler::instance()

class GameObjectHandler
{
    

    
    static GameObjectHandler *handler;
    GameObjectHandler()
    {
        
    }
    ~GameObjectHandler()
    {
       // objects.clear();
    }
    
public:
    static GameObjectHandler *instance()
    {
        if (!handler)
            handler = new GameObjectHandler();
        return handler;
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