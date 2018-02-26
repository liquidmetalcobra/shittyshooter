//
//  bulletgenerator.cpp
//  testgame
//
//  Created by Sasha Han on 10/14/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "BulletFactory.hpp"
void BulletFactory::generateBullet(Vector_2D location, Vector_2D velocity, int id)
{
        bullet *b = new bullet(location,velocity,id);
        bullets[count] = b;
        G_Handler->add(b);
}
void BulletFactory::draw()
{
    

}

void BulletFactory::update()
{
 
      
}