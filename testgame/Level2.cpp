//
//  Level2.cpp
//  testgame
//
//  Created by Sasha Han on 12/10/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "Level2.hpp"
void Level2::init()
{
    
    
    
    
    
    
    //needs to load
    
}
void Level2::load(PlayerShip *ps)
{
    
    G_Handler->empty();
     G_Collider->empty(COLLISION_CLASS_SHIP);
    G_Collider->empty(COLLISION_CLASS_BULLET);
    
    
    float bouncer_x = G_SCREEN_W / 2.0 - G_BOUNCER_SIZE / 2.0;
    float bouncer_y = G_SCREEN_H / 2.0 - G_BOUNCER_SIZE / 2.0;
    
    if (ps == NULL)
    {
        s = new PlayerShip(bouncer_x,bouncer_y,G_BOUNCER_SIZE+10,G_BOUNCER_SIZE);
    }
    else
    {
        s = ps;
        G_Collider->add(s, COLLISION_CLASS_SHIP);
        
    }
    
    HealthBar *hp = new HealthBar(20,20,400,100,s,&s->hp);
    enemyShip *e = new enemyShip(G_SCREEN_W-20,G_SCREEN_H/2,"witch");
    enemyShip *e2 = new enemyShip(G_SCREEN_W-20,G_SCREEN_H/3,"witch");
    enemyShip *e3 = new enemyShip(G_SCREEN_W-20,G_SCREEN_H*2/3,"witch");
    
    G_Handler->add(s);
    G_Handler->add(e);
    G_Handler->add(e2);
    G_Handler->add(e3);
    G_Handler->add(hp);
    
}
void Level2::draw()
{
    G_Handler->draw();
}


void Level2::update()
{
    G_Handler->update();
    G_Collider->update();
    
    if(s->hp <= 0)
    {
        nextLevel = 0;
        levelComplete = true;
    }
    if (G_Collider->getSize(COLLISION_CLASS_SHIP) == 1)
    {
        nextLevel = 0;
        levelComplete = true;
    }
    
   // cout << "size is " << handler->getSize() << "\n";
   // cout << "ships size is " << c->getSize(COLLISION_CLASS_SHIP) << "\n";
   // cout << "bullets size is " << c->getSize(COLLISION_CLASS_BULLET) << "\n\n";
}

void Level2::handleKeyboardEvent(ALLEGRO_EVENT ev)
{
    if (key[KEY_SPACE] && ev.keyboard.keycode == ALLEGRO_KEY_SPACE)
        s->fire();
}

void Level2::handleMouseEvent(ALLEGRO_EVENT ev)
{
    
}
