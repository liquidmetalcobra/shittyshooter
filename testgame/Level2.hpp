//
//  Level2.hpp
//  testgame
//
//  Created by Sasha Han on 12/10/17.
//  Copyright © 2017 __. All rights reserved.
//

#pragma once
#include <iostream>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "globals.h"
#include "Level.hpp"

#include "enemyShip.hpp"
#include "Collider.hpp"
#include "GameObjectHandler.hpp"
#include "HealthBar.hpp"

using namespace std;

class Level2 : public Level{
public:
    Level2() : Level()
    {
        levelID = 2;
        nextLevel = 2;
        
        
        
        init();
    }
    ~Level2()
    {
    }
    void init();
    void draw();
    void update();
    void load(PlayerShip *ps);
    void handleKeyboardEvent ( ALLEGRO_EVENT ev);
    void handleMouseEvent ( ALLEGRO_EVENT ev);
    
protected:
  
    
};




