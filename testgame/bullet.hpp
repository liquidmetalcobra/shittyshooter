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
class bullet: public gameobject {
public:
    bullet(int iX, int iY, int xVel, int yVel, int iID, collider* newCollider)
    {
        
        x = iX;
        y = iY;
        vel[0] = xVel;
        vel[1] = yVel;
        id = iID;
        c = newCollider;
        w = h = 10;
        b = al_create_bitmap(10, 10);
        c->add(this, COLLISION_CLASS_BULLET);
        al_set_target_bitmap(b);
        al_clear_to_color(al_map_rgb(255, 0, 0));

    }
    ~bullet()
    {
     //   std::cout << "bullet Dying\n\n";
        al_destroy_bitmap(b);
    }
    
    collider * c;
    void collide(gameobject *go);
    void update();
    void init();
    void draw();
    void destroy();
    
    
private:
    ALLEGRO_BITMAP *b;
    
    int vel[2];
};