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

class EmptyGameObject: public gameobject {
public:
    EmptyGameObject()
    {
        collisionClass = COLLISION_CLASS_NONE;
        
        
    }
    ~EmptyGameObject()
    {
        
    }
    void collide(gameobject *go);
    void update();
    void init();
    void draw(ALLEGRO_DISPLAY *display);
    void destroy();
    
    
    
    
    
protected:
    
    
    
};





