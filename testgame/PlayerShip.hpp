//
//  PlayerShip.hpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//
#pragma once

#ifndef PlayerShip_hpp
#define PlayerShip_hpp

#include <stdio.h>
#include "ship.hpp"
#endif /* PlayerShip_hpp */
class PlayerShip : public ship
{
public:
    PlayerShip(Vector_2D loc, Vector_2D siz) : ship(loc, siz)
    {
        
        
        b = al_load_bitmap("playership.png");
      //  al_set_target_bitmap(b);
        id = GAME_OBJECT_ID_PLAYERSHIP;
        spriteSize.x = 224;
        spriteSize.y = 154;
        hp = 100;
        hpMax = 100;
        gold = 100;

    }
    ~PlayerShip()
    {
    //    std::cout << "PLAYER SHIP DYING";
    }
    void collide(gameobject *go);
    void fire();
    void update();
    
    int gold;
private:
    
};