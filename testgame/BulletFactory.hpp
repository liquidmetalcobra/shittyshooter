//
//  bulletgenerator.hpp
//  testgame
//
//  Created by Sasha Han on 10/14/17.
//  Copyright © 2017 __. All rights reserved.
//
#pragma once

#include "iostream"
#include "bullet.hpp"
#include "Collider.hpp"
class BulletFactory {
public:
    
    BulletFactory()
    {
        count = 0;
    }
    ~BulletFactory()
    {
    /*    std::cout << "factory dying\n\n";
        for (int i = 0; i < count; i++)
        {
        //    G_Handler->remove(bullets[i]);
            delete bullets[i];
        }//*/
    }
    
    void generateBullet(Vector_2D location, Vector_2D velocity, int id);
    void update();
    void draw(ALLEGRO_DISPLAY *display);
private:
    
    bullet* bullets[10];
    int count;
};