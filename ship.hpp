//
//  ship.hpp
//  testgame
//
//  Created by Sasha Han on 10/14/17.
//  Copyright © 2017 __. All rights reserved.
//

#pragma once
#include <iostream>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "globals.h"
#include "gameObject.hpp"
#include "BulletFactory.hpp"
#include "Collider.hpp"
using namespace std;

class ship: public gameobject {
public:
    ship(Vector_2D loc, Vector_2D siz)
    {
        location = loc;
        size = siz;
        
        collisionClass = COLLISION_CLASS_SHIP;
        bulletGen = new BulletFactory();
        
    }
    ~ship()
    {
        std::cout << "ship dying";
        if (b != NULL)
        {
            
            al_destroy_bitmap(b);
            b = NULL;
        }
        if (bulletGen != NULL)
            delete bulletGen;
    }
    void collide(gameobject *go);
    virtual void update();
    void init();
    void draw();
    void destroy();
    
    int getHP() { return hp; }
    
    virtual void fire();
    
    //void move (Vector_2D delta);
    void move (int x, int y);

    int hp;
protected:
    ALLEGRO_BITMAP *b;
    
    Vector_2D spriteSize;
    
    BulletFactory *bulletGen;
    
    
   
};





