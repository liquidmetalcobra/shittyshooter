//
//  globals.h
//  testgame
//
//  Created by Sasha Han on 10/14/17.
//  Copyright © 2017 __. All rights reserved.
//
#pragma once
#include <iostream>
extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}
#include <unistd.h>
#include "LuaBridge/LuaBridge.h"
#include "VectorMath.hpp"

enum collisionClasses { COLLISION_CLASS_NONE, COLLISION_CLASS_SHIP, COLLISION_CLASS_BULLET, COLLISION_CLASS_POWERUP};
enum GameObjectID { GAME_OBJECT_ID_POWERUP = -1, GAME_OBJECT_ID_PLAYERSHIP, GAME_OBJECT_ID_ENEMYSHIP};

#define G_FPS GlobalConfig::instance()->FPS()
#define G_SCREEN_W GlobalConfig::instance()->SCREEN_W()
#define G_SCREEN_H GlobalConfig::instance()->SCREEN_H()
#define G_BOUNCER_SIZE GlobalConfig::instance()->BOUNCER_SIZE()
#define G_LEVEL_SCRIPT_LOCATION GlobalConfig::instance()->LEVEL_SCRIPT_LOCATION()
#define G_ENEMY_SCRIPT_LOCATION GlobalConfig::instance()->ENEMY_SCRIPT_LOCATION()
#define G_FONT_LOCATION GlobalConfig::instance()->FONT_LOCATION()



const int NUM_KEYS = 7;
enum MYKEYS {
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE, KEY_F, KEY_ESCAPE
};

struct VECTOR_2D {
    int x;
    int y;
};

struct VECTOR_3D {
    int x;
    int y;
    int z;
};
typedef struct VECTOR_2D V2D;
typedef struct VECTOR_3D V3D;





extern bool key[NUM_KEYS];


class GlobalConfig
{
    static GlobalConfig *g;
    GlobalConfig() {
        
        lua_State* L = luaL_newstate();
        
        std::cout << luaL_dofile(L, "Scripts/Globals.lua");
        
        luaL_openlibs(L);
        lua_pcall(L, 0, 0, 0);
        
        _FPS = luabridge::getGlobal(L, "FPS").cast<float>();
        _SCREEN_W = luabridge::getGlobal(L, "SCREEN_W").cast<int>();
        _SCREEN_H = luabridge::getGlobal(L, "SCREEN_H").cast<int>();
        _BOUNCER_SIZE = luabridge::getGlobal(L, "BOUNCER_SIZE").cast<int>();
        _LEVEL_SCRIPT_LOCATION = luabridge::getGlobal(L, "LEVEL_SCRIPT_LOCATION").cast<std::string>();
        _ENEMY_SCRIPT_LOCATION = luabridge::getGlobal(L, "ENEMY_SCRIPT_LOCATION").cast<std::string>();
        _FONT_LOCATION = luabridge::getGlobal(L, "FONT_LOCATION").cast<std::string>();
        
    }
    ~GlobalConfig(){}
    
    float _FPS;
    int _SCREEN_W;
    int _SCREEN_H;
    int _BOUNCER_SIZE;
    std::string _LEVEL_SCRIPT_LOCATION;
    std::string _ENEMY_SCRIPT_LOCATION;
    std::string _FONT_LOCATION;
    
public:
    static GlobalConfig *instance()
    {
        if (!g)
            g = new GlobalConfig();
        return g;
    }
    float FPS() { return _FPS; }
    int SCREEN_W() { return _SCREEN_W; }
    int SCREEN_H() { return _SCREEN_H; }
    int BOUNCER_SIZE() { return _BOUNCER_SIZE; }
    std::string LEVEL_SCRIPT_LOCATION() { return _LEVEL_SCRIPT_LOCATION; }
    std::string ENEMY_SCRIPT_LOCATION() { return _ENEMY_SCRIPT_LOCATION; }
    std::string FONT_LOCATION() { return _FONT_LOCATION; }
    
};


