//
//  MainMenu.cpp
//  testgame
//
//  Created by Sasha Han on 12/10/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "MainMenu.hpp"
void MainMenu::init()
{
    
    but = new Button(50,50,100,100, NULL);
    
    
    levelID = 0;
    nextLevel = 0;
    handler->add(but);
    
    
    s = NULL;

    
    
}
void MainMenu::load(PlayerShip *ps)
{
    handler->empty();
    c->empty(COLLISION_CLASS_SHIP);
    c->empty(COLLISION_CLASS_BULLET);
    
    handler->add(but);
}
void MainMenu::draw()
{
    handler->draw();
}


void MainMenu::update()
{
    handler->update();
}

void MainMenu::handleKeyboardEvent(ALLEGRO_EVENT ev)
{
    
    
}

void MainMenu::handleMouseEvent(ALLEGRO_EVENT ev)
{
    if(but->isButtonClicked(ev.mouse.x, ev.mouse.y))
    {
        nextLevel = 1;
        levelComplete = true;
    }
}
