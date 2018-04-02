//
//  Window.hpp
//  testgame
//
//  Created by Sasha Han on 10/22/17.
//  Copyright © 2017 __. All rights reserved.
//

#pragma once


#include <iostream>
#include "UIElement.hpp"
#include "Button.hpp"

class Window : public UIElement
{
    
public:
    Window(Vector_2D loc, Vector_2D size, void * callBack) : UIElement(loc,size,NULL)
    {
        //WindowPressed = (void *)callBack;
        
        b = al_create_bitmap(size.x, size.y);
        al_set_target_bitmap(b);
        al_clear_to_color(al_map_rgb(0, 0, 0));
        
        
        background = al_create_bitmap(size.x, size.y);
        al_set_target_bitmap(background);
        al_clear_to_color(al_map_rgb(255, 255, 255));
    }
    ~Window()
    {
        al_destroy_bitmap(b);
        al_destroy_bitmap(background);
    }
    void update();
    void init();
    void draw();
    void destroy();
    bool isWindowClicked(int mbX, int mbY);
    
    
protected:
    
private:
    std::vector<Button*> buttons;
    void (*WindowPressed)(void);
    
    
    
    
};