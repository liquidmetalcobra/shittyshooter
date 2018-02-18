//
//  keyboardmanager.cpp
//  testgame
//
//  Created by Sasha Han on 10/14/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "keyboardmanager.hpp"



void updateKeyboardKeyState(int keyCode, bool state)
{
    switch(keyCode) {
        case ALLEGRO_KEY_UP:
            key[KEY_UP] = state;
            break;
            
        case ALLEGRO_KEY_DOWN:
            key[KEY_DOWN] = state;
            break;
            
        case ALLEGRO_KEY_LEFT:
            key[KEY_LEFT] = state;
            break;
            
        case ALLEGRO_KEY_RIGHT:
            key[KEY_RIGHT] = state;
            break;
        case ALLEGRO_KEY_SPACE:
            key[KEY_SPACE] = state;
            break;
            
        case ALLEGRO_KEY_ESCAPE:
            key[KEY_ESCAPE] = state;
            break;
    }
   // printKeyboardState();
}


void printKeyboardState()
{
    printf("\n");
    for (int i = 0; i < NUM_KEYS; i++)
        printf("%d\t",key[i]);
    
}