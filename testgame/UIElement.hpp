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
    
    UIElement(int iX, int iY, int iW, int iH, gameobject * go)
    {
        x = iX;
        y = iY;
        w = iW;
        h = iH;
        object = go;
  
    }
    ~UIElement()
    {
        
    }
    virtual void update() = 0;
    virtual void init() = 0;
    virtual void draw() = 0;
    virtual void destroy() = 0;
    
protected:
    ALLEGRO_BITMAP *b;
    ALLEGRO_BITMAP *background;
    gameobject* object;
private:
    
};