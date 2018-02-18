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
    
    handler->empty();
     c->empty(COLLISION_CLASS_SHIP);
    c->empty(COLLISION_CLASS_BULLET);
    
    
    float bouncer_x = G_SCREEN_W / 2.0 - G_BOUNCER_SIZE / 2.0;
    float bouncer_y = G_SCREEN_H / 2.0 - G_BOUNCER_SIZE / 2.0;
    
    if (ps == NULL)
    {
        s = new PlayerShip(bouncer_x,bouncer_y,G_BOUNCER_SIZE+10,G_BOUNCER_SIZE,c);
    }
    else
    {
        s = ps;
        c->add(s, COLLISION_CLASS_SHIP);
        
    }
    
    HealthBar *hp = new HealthBar(20,20,400,100,s,&s->hp);
    enemyShip *e = new enemyShip(G_SCREEN_W-20,G_SCREEN_H/2,"witch",c);
    enemyShip *e2 = new enemyShip(G_SCREEN_W-20,G_SCREEN_H/3,"witch",c);
    enemyShip *e3 = new enemyShip(G_SCREEN_W-20,G_SCREEN_H*2/3,"witch",c);
    
    handler->add(s);
    handler->add(e);
    handler->add(e2);
    handler->add(e3);
    handler->add(hp);
    
}
void Level2::draw()
{
    handler->draw();
}


void Level2::update()
{
    handler->update();
    c->update();
    
    if(s->hp <= 0)
    {
        nextLevel = 0;
        levelComplete = true;
    }
    if (c->getSize(COLLISION_CLASS_SHIP) == 1)
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
