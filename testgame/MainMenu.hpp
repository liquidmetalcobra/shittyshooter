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
#include "BaseLevel.hpp"
#include "GameObjectHandler.hpp"

#include "Button.hpp"
using namespace std;

class MainMenu : public BaseLevel{
public:
    MainMenu() : BaseLevel()
    {
        init();
    }
    ~MainMenu()
    {
    }
    void init();
    void draw(ALLEGRO_DISPLAY *display);
    void update();
    void load(PlayerShip *ps);
    void handleKeyboardEvent ( ALLEGRO_EVENT ev);
    void handleMouseEvent ( ALLEGRO_EVENT ev);
    
protected:
    
    Button *but;
    
    std::vector<Button*> lvlSelect;
    
};




