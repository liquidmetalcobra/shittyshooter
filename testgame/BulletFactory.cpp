//
//  bulletgenerator.cpp
//  testgame
//
//  Created by Sasha Han on 10/14/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "BulletFactory.hpp"
void BulletFactory::generateBullet(int x, int y, int xVel, int yVel, int id)
{

    
    if (count < 10)
    {
        bullet *b = new bullet(x,y,xVel,yVel,id,c);
        bullets[count] = b;
        count++;
    }
}
void BulletFactory::draw()
{
    
    for (int i = 0; i < count; i++)
        bullets[i]->draw();
}

void BulletFactory::update()
{
 
    for (int i = 0; i < count; i++)
    {
        
        if (bullets[i]->markForDeath)
        {
            bullets[i]->destroy();
            bullets[i]=NULL;
            bullets[i] = bullets[count-1];
            count--;
            i--;
        }
        else
        {
            bullets[i]->update();
        }
    }
    
}