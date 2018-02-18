//
//  Level1.hpp
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
#include "GameObjectHandler.hpp"

#include "Button.hpp"
using namespace std;

class MainMenu : public Level{
public:
    MainMenu(collider *c, GameObjectHandler *handler) : Level(c, handler)
    {
        init();
    }
    ~MainMenu()
    {
        delete handler;
    }
    void init();
    void draw();
    void update();
    void load(PlayerShip *ps);
    void handleKeyboardEvent ( ALLEGRO_EVENT ev);
    void handleMouseEvent ( ALLEGRO_EVENT ev);
    
protected:
    
    Button *but;
   
    
};




