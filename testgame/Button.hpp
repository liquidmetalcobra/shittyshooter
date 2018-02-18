//
//  Button.hpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#pragma once


#include <iostream>
#include "UIElement.hpp"


class Button : public UIElement
{
    
public:
    Button(int iX, int iY, int iW, int iH, void * callBack) : UIElement(iX,iY,iW,iH,NULL)
    {
        //buttonPressed = (void *)callBack;
        
        b = al_create_bitmap(w, h);
        al_set_target_bitmap(b);
        al_clear_to_color(al_map_rgb(255, 0, 0));
        
        
        background = al_create_bitmap(w, h);
        al_set_target_bitmap(background);
        al_clear_to_color(al_map_rgb(255, 255, 255));
    }
    ~Button()
    {
        al_destroy_bitmap(b);
        al_destroy_bitmap(background);
    }
    void update();
    void init();
    void draw();
    void destroy();
    bool isButtonClicked(int mbX, int mbY);
    
    
protected:
    
private:
    
    void (*buttonPressed)(void);
    
    
    
    
};