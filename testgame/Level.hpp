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
#include "HelperShip.hpp"
#include "Collider.hpp"
#include "GameObjectHandler.hpp"
#include "HealthBar.hpp"
#include "EmptyGameObject.hpp"
#include "LevelUI.hpp"
using namespace std;

class Level : public BaseLevel{
public:
    Level(int level) : BaseLevel()
    {
        
        std::string fontName = G_FONT_LOCATION + "8bit.ttf";
        //buttonPressed = (void *)callBack;
        font = al_load_ttf_font(fontName.c_str(),30,0 );
        float alpha = 1.0f;
        color = al_map_rgba_f(1.0*alpha, 1.0*alpha, 1.0*alpha, alpha); // <-- correct
        
        
 
        
        init(level);
    }
    ~Level()
    {
      
       
    }
    void init();
    void init(int level);
    void draw(ALLEGRO_DISPLAY *display);
    void update();
    void load(PlayerShip *ps);
    void handleKeyboardEvent ( ALLEGRO_EVENT ev);
    void handleMouseEvent ( ALLEGRO_EVENT ev);
    bool loadWave(int waveID);
protected:
   
    int numberOfWaves;
    int currentWave;
    int defaultNextLevel;
    EmptyGameObject *swarmContainer;
    LevelUI *ui;
    lua_State* LevelState;
    
    ALLEGRO_FONT *font;
    ALLEGRO_COLOR color;
    
};

    
    
    
    