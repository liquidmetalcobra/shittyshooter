//
//  LevelUI.hpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#pragma once


#include <iostream>
#include "UIElement.hpp"
#include "Button.hpp"
#include "PlayerShip.hpp"
#include "EmptyGameObject.hpp"
#include "HealthBar.hpp"
#include "TextBox.hpp"
#include "IntTextBox.hpp"

class LevelUI : public gameobject
{
    
public:
    LevelUI(PlayerShip *go)
    {
        //LevelUIPressed = (void *)callBack;
        
        s = go;
        
        Vector_2D loc(20,20);
        Vector_2D size(400,100);
        
        ALLEGRO_COLOR c = al_map_rgb(212, 175, 55);
        hp = new HealthBar(Vector_2D(20,20),Vector_2D(300,80),s,&s->hp,&s->hpMax);
        gold = new IntTextBox(Vector_2D(340,20),Vector_2D(80,80),"$",&c,&s->gold);
        score = new IntTextBox(Vector_2D(440,20),Vector_2D(300,80),"",NULL,&gScore);
        printf("HIHIHIHI s hp max is %d",s->hpMax);
        G_Handler->add(hp);
        G_Handler->add(gold);
        G_Handler->add(score);
        
        
        init();
        
    }
    ~LevelUI()
    {
      
    }
        
    void collide(gameobject *go);
    void update();
    void init();
    void draw(ALLEGRO_DISPLAY *display);
    void destroy();
    
protected:
    
private:
    std::vector<Button*> buttons;
    
    PlayerShip *s;
    
    HealthBar *hp;
    TextBox *gold;
    TextBox *score;
    
    
};