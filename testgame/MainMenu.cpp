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
    G_Handler->add(but);
    
    
    s = NULL;

    
    
}
void MainMenu::load(PlayerShip *ps)
{
    G_Handler->empty();
    G_Collider->empty(COLLISION_CLASS_SHIP);
    G_Collider->empty(COLLISION_CLASS_BULLET);
    
    G_Handler->add(but);
}
void MainMenu::draw()
{
    G_Handler->draw();
}


void MainMenu::update()
{
    G_Handler->update();
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
