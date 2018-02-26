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
#include "GameObjectHandler.hpp"

class bullet: public gameobject {
public:
    bullet(Vector_2D loc, Vector_2D vel, int iID)
    {
        collisionClass = COLLISION_CLASS_BULLET;
        location = loc;
        velocity = vel;
        size = Vector_2D(10,10);
        id = iID;
        
        b = al_create_bitmap(10, 10);
        
        al_set_target_bitmap(b);
        al_clear_to_color(al_map_rgb(255, 0, 0));

    }
    ~bullet()
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
    
    Vector_2D velocity;;
};