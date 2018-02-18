//
//  GameObjectHandler.cpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "GameObjectHandler.hpp"
void GameObjectHandler::add(gameobject* a)
{
    objects.push_back(a);
}
void GameObjectHandler::remove(gameobject * r)
{
    
    objects.erase(std::remove(objects.begin(), objects.end(), r), objects.end());
}

void GameObjectHandler::update()
{
    //std::cout << "number of ships is "
    for (int i = 0; i < objects.size(); i++)
    {
        if (objects[i]->markForDeath)
        {
            objects[i]->destroy();
            objects[i] = NULL;
            objects.erase(objects.begin()+i);
            i--;
        }
        else
        {
            objects[i]->update();
        }
        
        
    }
    
    
    
}

void GameObjectHandler::draw()
{
    for (int i = 0; i < objects.size(); i++)
        objects[i]->draw();
}