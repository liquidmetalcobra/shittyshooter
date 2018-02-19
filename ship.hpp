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
    ship(int iX, int iY, int iW, int iH)
    {
        x = iX;
        y = iY;
        w = iW;
        h = iH;
        
        
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
    
    void move (int dX, int dY);

    int hp;
protected:
    ALLEGRO_BITMAP *b;
    int s_w;
    int s_h;
    BulletFactory *bulletGen;
    
    
   
};





