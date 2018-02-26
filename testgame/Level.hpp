//
//  Level.hpp
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
#include "BaseLevel.hpp"
#include "PowerUp.hpp"
#include "enemyShip.hpp"
#include "Collider.hpp"
#include "GameObjectHandler.hpp"
#include "HealthBar.hpp"

using namespace std;

class Level : public BaseLevel{
public:
    Level(int level) : BaseLevel()
    {
        
        
        
        init(level);
    }
    ~Level()
    {
      
       
    }
    void init();
    void init(int level);
    void draw();
    void update();
    void load(PlayerShip *ps);
    void handleKeyboardEvent ( ALLEGRO_EVENT ev);
    void handleMouseEvent ( ALLEGRO_EVENT ev);
    bool loadWave(int waveID);
protected:
   
    int numberOfWaves;
    int currentWave;
    int defaultNextLevel;
    lua_State* LevelState;
    
};

    
    
    
    