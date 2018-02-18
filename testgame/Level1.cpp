//
//  Level1.cpp
//  testgame
//
//  Created by Sasha Han on 12/10/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "Level1.hpp"
#include <sstream>
void Level1::init()
{
    
}
void Level1::init(int level)
{
    LevelState = luaL_newstate();
 
    stringstream ss;
    ss << level;//add number to the stream
    
    string scriptLocation = G_LEVEL_SCRIPT_LOCATION + "Level" + ss.str() + ".lua";
    cout << scriptLocation << "\n";
    
    
    std::cout << luaL_dofile(LevelState, scriptLocation.c_str());
    
    luaL_openlibs(LevelState);
    lua_pcall(LevelState, 0, 0, 0);
    
    //_FPS = luabridge::getGlobal(L, "FPS").cast<float>();
    
    levelID = luabridge::getGlobal(LevelState,"LevelID").cast<int>();
    nextLevel = luabridge::getGlobal(LevelState,"NextLevel").cast<int>();
    defaultNextLevel = nextLevel;
    numberOfWaves = luabridge::getGlobal(LevelState,"NumWaves").cast<int>();
    currentWave = 1;
    
   
    //needs to load
    
}
void Level1::load(PlayerShip *ps)
{
    float bouncer_x = G_SCREEN_W / 2.0 - G_BOUNCER_SIZE / 2.0;
    float bouncer_y = G_SCREEN_H / 2.0 - G_BOUNCER_SIZE / 2.0;
    currentWave = 1;
    nextLevel = defaultNextLevel;
    handler->empty();
    c->empty(COLLISION_CLASS_SHIP);
    c->empty(COLLISION_CLASS_BULLET);
    
    if (ps == NULL)
        s = new PlayerShip(bouncer_x,bouncer_y,G_BOUNCER_SIZE+10,G_BOUNCER_SIZE,c);
    else
    {
        s = ps;
        c->add(s, COLLISION_CLASS_SHIP);
    }
    
    
    HealthBar *hp = new HealthBar(20,20,400,100,s,&s->hp);
    
    
    loadWave(currentWave);
    
    handler->add(s);
    
    handler->add(hp);

}

bool Level1::loadWave(int waveID)
{
    if (waveID > numberOfWaves)
        return false;
    
    
    luabridge::LuaRef table = luabridge::getGlobal(LevelState, "Waves");
    if (table.isTable()) {
        stringstream ss;
        ss << waveID;//add number to the stream

        string waveName = "Wave" + ss.str();
        cout << waveName << "\n";
        luabridge::LuaRef wave = table[waveName];
        if (wave.isTable()) {
            int enemiesInWave = wave["numEnemies"].cast<int>();
            cout << enemiesInWave;
            for (int i = 1; i <= enemiesInWave; i++)
            {
                luabridge::LuaRef enemy = wave[i];
                
                float x = enemy["ix"].cast<float>();
                
                float y = enemy["iy"].cast<float>();
                string name = enemy["name"].cast<string>();
                enemyShip *e = new enemyShip(G_SCREEN_W*x/100,G_SCREEN_H*y/100,name,c);
                handler->add(e);
            }
            
            fprintf(stderr, "%s\n", lua_tostring(LevelState, -1));
         //   cout << tab;
        } else {
            std::cout << "can't find table";
            return false;
        }
    }
    PowerUp *p = new PowerUp(700,500,-5,5,-1,c);
    handler->add(p);
    return true;
}
void Level1::draw()
{
    handler->draw();
}


void Level1::update()
{
    handler->update();
    c->update();
    
    if(s->hp <= 0)
        nextLevel = 0;
    if (c->getSize(COLLISION_CLASS_SHIP) == 1)
    {
        currentWave+=1;
        loadWave(currentWave);
    }
    if (currentWave > numberOfWaves || s->hp <= 0)
        levelComplete = true;
   // cout << "size is " << handler->getSize() << "\n";
    //cout << "ships size is " << c->getSize(COLLISION_CLASS_SHIP) << "\n";
    //cout << "bullets size is " << c->getSize(COLLISION_CLASS_BULLET) << "\n\n";
}

void Level1::handleKeyboardEvent(ALLEGRO_EVENT ev)
{
    if (key[KEY_SPACE] && ev.keyboard.keycode == ALLEGRO_KEY_SPACE)
        s->fire();
}

void Level1::handleMouseEvent(ALLEGRO_EVENT ev)
{
    
}
