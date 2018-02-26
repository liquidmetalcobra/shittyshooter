//
//  LevelLoader.hpp
//  testgame
//
//  Created by Sasha Han on 12/10/17.
//  Copyright © 2017 __. All rights reserved.
//
#pragma once
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "globals.h"
#include "BaseLevel.hpp"
#include "MainMenu.hpp"
#include "Level.hpp"

#include <vector>

class LevelLoader {
public:
    
    LevelLoader()
    {
        init();
    }
    ~LevelLoader()
    {
     
    }
    
    void init();
    void draw();
    void update();
    
    void handleKeyboardEvent ( ALLEGRO_EVENT ev);
    void handleMouseEvent ( ALLEGRO_EVENT ev);
    
    
private:
    std::vector<BaseLevel*> levels;
    int currentLevel;
    
    GameObjectHandler *handler;
    
};