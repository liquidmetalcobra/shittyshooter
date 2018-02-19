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
        bullet *b = new bullet(x,y,xVel,yVel,id);
        bullets[count] = b;
        G_Handler->add(b);
}
void BulletFactory::draw()
{
    

}

void BulletFactory::update()
{
 
      
}