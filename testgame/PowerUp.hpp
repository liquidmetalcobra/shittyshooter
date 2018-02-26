//
//  bullet.hpp
//  testgame
//
//  Created by Sasha Han on 10/14/17.
//  Copyright © 2017 __. All rights reserved.
//
#pragma once
#include "gameobject.hpp"
#include <stdio.h>
#include "allegro5/allegro.h"
#include "Collider.hpp"
class PowerUp: public gameobject {
public:
    PowerUp(Vector_2D loc, Vector_2D vel)
    {
        collisionClass = COLLISION_CLASS_POWERUP;
        timeToLive = 500;
        
        location = loc;
        velocity = vel;
        size = Vector_2D(10,10);
        id = GAME_OBJECT_ID_POWERUP;
        
        
        b = al_create_bitmap(10, 10);
        
        al_set_target_bitmap(b);
        al_clear_to_color(al_map_rgb(250, 250, 250));
        
    }
    ~PowerUp()
    {
        //   std::cout << "bullet Dying\n\n";
        al_destroy_bitmap(b);
    }
    
   
    void collide(gameobject *go);
    void update();
    void init();
    void draw();
    void destroy();
    
    
private:
    ALLEGRO_BITMAP *b;
    int timeToLive;
    Vector_2D velocity;
};