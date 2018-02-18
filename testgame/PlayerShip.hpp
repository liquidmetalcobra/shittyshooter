//
//  PlayerShip.hpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#ifndef PlayerShip_hpp
#define PlayerShip_hpp

#include <stdio.h>
#include "ship.hpp"
#endif /* PlayerShip_hpp */
class PlayerShip : public ship
{
public:
    PlayerShip(int iX, int iY, int iW, int iH, collider* newCollider) : ship(iX,iY,iW,iH,newCollider)
    {
        
        
        b = al_load_bitmap("playership.png");
      //  al_set_target_bitmap(b);
        
        s_w = 224;
        s_h = 154;
        hp = 100;

    }
    ~PlayerShip()
    {
    //    std::cout << "PLAYER SHIP DYING";
    }
    void collide(gameobject *go);
    void fire();
    void update();
    
    
private:
    
};