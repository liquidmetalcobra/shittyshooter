//
//  UIElement.hpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//
#pragma once

#include <iostream>
#include "gameobject.hpp"

class UIElement : public gameobject
{
public:
    
    UIElement(Vector_2D loc, Vector_2D siz, gameobject * go)
    {
        location = loc;
        size = siz;
        object = go;
  
    }
    ~UIElement()
    {
        
    }
    virtual void update() = 0;
    virtual void init() = 0;
    virtual void draw(ALLEGRO_DISPLAY *display) = 0;
    virtual void destroy() = 0;
    
protected:
    ALLEGRO_BITMAP *b;
    ALLEGRO_BITMAP *background;
    gameobject* object;
    ALLEGRO_FONT *font;
    ALLEGRO_COLOR color;
private:
    
};