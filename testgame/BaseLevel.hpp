//
//  BaseLevel.hpp
//  testgame
//
//  Created by Sasha Han on 12/10/17.
//  Copyright © 2017 __. All rights reserved.
//

#pragma once
#include <iostream>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "PlayerShip.hpp"
#include "globals.h"
#include "Collider.hpp"
#include "GameObjectHandler.hpp"

using namespace std;

class BaseLevel {
public:
    BaseLevel()
    {
        levelComplete = false;
    }
    ~BaseLevel()
    {
        delete s;
        
    }
    virtual void init() = 0;
    virtual void draw(ALLEGRO_DISPLAY *display) = 0;
    virtual void load(PlayerShip *ps) = 0;
    virtual void update() = 0;
    virtual void handleKeyboardEvent ( ALLEGRO_EVENT ev) = 0;
    virtual void handleMouseEvent ( ALLEGRO_EVENT ev) = 0;
    
    int GetNextLevel() { return nextLevel; };
    void SetNextLevel(int newNextLevel) { nextLevel = newNextLevel; };
    bool levelComplete;
    PlayerShip *s; 
protected:
    int nextLevel;
    int levelID;
    
    
    
};





