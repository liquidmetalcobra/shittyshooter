//
//  ship.cpp
//  testgame
//
//  Created by Sasha Han on 10/14/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "ship.hpp"


void ship::move(int dX, int dY)
{
    //printf("Moving by (%d, %d)",dX,dY);
    
    x+=dX;
    y+=dY;
    
}

void ship::update()
{

}
void ship::fire()
{
    
 
}
void ship::draw()
{
    
    al_draw_scaled_bitmap(b, 0, 0, s_w, s_h, x, y, this->w, this->h, 0);
    bulletGen->draw();
}
void ship::collide(gameobject *go)
{
    //cout << "\n Collided with object of ID " << go->getID()  << " compared to this id: " << getID();
    if (go->getID() != getID())
        cout << "ow";
    //   std::cout << "oops";
}

void ship::destroy()
{
    G_Collider->remove(this);
    this->~ship();
    
}

void ship::init()
{
    
}

