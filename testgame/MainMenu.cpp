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
    Vector_2D loc(50,50);
    Vector_2D size(100,100);
    
    std::function<void(void)> f = [&](void)->void { this->nextLevel =1; this->levelComplete = true;};
    std::string n = "Start Game";
    but = new Button(loc,size, &n, f);
    
    
    for (int i = 0; i < 3; i++)
    {
        
        std::string n = itos(i+1);
        std::function<void(void)> g = [&,i](void)->void {this->nextLevel = i+1; this->levelComplete = true;};
        Button *tempBut = new Button(Vector_2D(200,50+120*i),size,&n,g);
        G_Handler->add(tempBut);
        lvlSelect.push_back(tempBut);
    }
    
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
    for (int i = 0; i < 3; i++)
    {
        G_Handler->add(lvlSelect[i]);
    }
}
void MainMenu::draw(ALLEGRO_DISPLAY *display)
{
    G_Handler->draw(display);
}


void MainMenu::update()
{
    G_Handler->update();
}

void MainMenu::handleKeyboardEvent(ALLEGRO_EVENT ev)
{
    //if (key[KEY_ESCAPE] && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        
    
}

void MainMenu::handleMouseEvent(ALLEGRO_EVENT ev)
{
    but->isButtonClicked(ev.mouse.x, ev.mouse.y);
    for (int i = 0; i < 3; i++)
        lvlSelect[i]->isButtonClicked(ev.mouse.x, ev.mouse.y);
    
}
