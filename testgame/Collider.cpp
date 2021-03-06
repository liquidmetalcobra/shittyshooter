//
//  Collider.cpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "Collider.hpp"
collider *collider::col = 0;

long collider::getSize(collisionClasses c)
{
    if(c==COLLISION_CLASS_SHIP)
        return ships.size();
    if (c==COLLISION_CLASS_BULLET)
        return bullets.size();
    if (c==COLLISION_CLASS_POWERUP)
        return powerups.size();
    
    
    return -1;
}
void collider::empty(collisionClasses c)
{
    if(c==COLLISION_CLASS_SHIP)
        ships.clear();
    if (c==COLLISION_CLASS_BULLET)
        bullets.clear();
    if (c==COLLISION_CLASS_BULLET)
        powerups.clear();
    
    
    
}
void collider::update()
{
 
    unsigned long s = ships.size();
    unsigned long b = bullets.size();
    unsigned long p = powerups.size();
    for(int i = 0; i < s; i++)
        for (int j = 0; j < b; j++)
        {
            
            if (!bullets[j]->markForDeath && !ships[i]->markForDeath && checkCollision(ships[i], bullets[j]))
            {
               // printf("Bullet %d and Ship %d collision\n",j,i);
                ships[i]->collide(bullets[j]);
                bullets[j]->collide(ships[i]);
             
            }
        }
    for(int i = 0; i < s; i++)
        for (int j = 0; j < p; j++)
        {
            
            if (!powerups[j]->markForDeath && !ships[i]->markForDeath && checkCollision(ships[i], powerups[j]))
            {
                // printf("Bullet %d and Ship %d collision\n",j,i);
                ships[i]->collide(powerups[j]);
                powerups[j]->collide(ships[i]);
            }
        }
    for(int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
        {
            
            if ((i!=j) && checkCollision(ships[i], ships[j]))
            {
          //      printf("Ship %d and Ship %d collision",i,j);
                ships[i]->collide(ships[j]);
                ships[j]->collide(ships[i]);
            }
        }
    
}

void collider::add(gameobject* a, collisionClasses id)
{
    
    if(id==COLLISION_CLASS_SHIP)
        ships.push_back(a);
    else if (id==COLLISION_CLASS_BULLET)
        bullets.push_back(a);
    else if (id==COLLISION_CLASS_POWERUP)
        powerups.push_back(a);
}
void collider::remove(gameobject * r)
{
    
    ships.erase(std::remove(ships.begin(), ships.end(), r), ships.end());
    bullets.erase(std::remove(bullets.begin(), bullets.end(), r), bullets.end());
    powerups.erase(std::remove(powerups.begin(), powerups.end(), r), powerups.end());
}
bool collider::checkCollision(gameobject* a, gameobject* b)
{
    /*
    if (!a || !b)
    {
        if (!a) remove(a);
        if (!b) remove(b);
    
        return false;
    }*/
    
    float ax,ay,bx,by;
    ax = a->getAbsoluteLocation().x;
    ay = a->getAbsoluteLocation().y;
    bx = b->getAbsoluteLocation().x;
    by = b->getAbsoluteLocation().y;
    int aw = a->getWidth();
    int ah = a->getHeight();
    int bw = b->getWidth();
    int bh = b->getHeight();
    if ((ax > bx + bw - 1) || // is a on the right side of b?
        (ay > by + bh - 1) || // is b1 under b2?
        (bx > ax + aw - 1) || // is b2 on the right side of b1?
        (by > ay + ah - 1))   // is b2 under b1?
    {
    
        return 0;
    }
    
    // collision
    return 1;
    
    
}