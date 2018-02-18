//
//  keyboardmanager.hpp
//  testgame
//
//  Created by Sasha Han on 10/14/17.
//  Copyright © 2017 __. All rights reserved.
//

#pragma once
#include <stdio.h>
#include "globals.h"
#include "allegro5/allegro.h"


void updateKeyboardKeyState(int keyCode, bool state);

void printKeyboardState();
