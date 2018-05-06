//
//  PlayerShip.cpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "PlayerShip.hpp"


void PlayerShip::update()
{
    
   // printf("hi");
    int x = location.x;
    int y = location.y;
    int w = size.x;
    int h = size.y;
    if(key[KEY_UP] && y >= 4.0 + G_SCREEN_CEILING) {
        move(0,-4);
        //move(Vector_2D(0,-4));
    }
    
    if(key[KEY_DOWN] && y <= G_SCREEN_H - h - 4.0) {
        move(0,4);
        //move(Vector_2D(0,4));
    }
    
    if(key[KEY_LEFT] && x >= 4.0) {
        move(-4,0);
        //move(Vector_2D(-4,0));
    }
    
    if(key[KEY_RIGHT] && x <= G_SCREEN_W - w - 4.0) {
        move(4,0);
        //move(Vector_2D(4,0));
    }
    bulletGen->update();
    //fire();
}

void PlayerShip::fire()
{
    Vector_2D loc = Add2DV(getAbsoluteLocation(),Vector_2D(size.x,size.y/4));
     bulletGen->generateBullet(loc,Vector_2D(10,0), getID());
}


void PlayerShip::collide(gameobject *go)
{
    if (go->getID() < 0)//hack hihihihi
    {
        switch(go->getID())
        {
            case GAME_OBJECT_ID_POWERUP_HEALTH:
            {
                hp = hp == hpMax ? hpMax : hp+10;
                break;
            }
            case GAME_OBJECT_ID_POWERUP_GOLD:
            {
                gold+=100;
                break;
            }
            case GAME_OBJECT_ID_POWERUP_SCORE:
            {
                gScore+=1000;
                break;
            }
            default:
                break;
                
        }
        
    }
    else if (go->getID() != getID())
    {
        hp-=10;
        if (hp<=0)
            markForDeath = true;
    }
}


