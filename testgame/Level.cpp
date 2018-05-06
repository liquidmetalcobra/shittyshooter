//
//  Level.cpp
//  testgame
//
//  Created by Sasha Han on 12/10/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "Level.hpp"
#include <sstream>
void Level::init()
{
    
}
void Level::init(int level)
{
    
    
    
    LevelState = luaL_newstate();
    
    swarmContainer = new EmptyGameObject;
    
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
void Level::load(PlayerShip *ps)
{
    float bouncer_x = G_SCREEN_W / 2.0 - G_BOUNCER_SIZE / 2.0;
    float bouncer_y = G_SCREEN_H / 2.0 - G_BOUNCER_SIZE / 2.0;
    currentWave = 1;
    nextLevel = defaultNextLevel;
    G_Handler->empty();
    G_Collider->empty(COLLISION_CLASS_SHIP);
    G_Collider->empty(COLLISION_CLASS_BULLET);
    swarmContainer->removeAllChildren();
    if (ps == NULL)
    {
        s = new PlayerShip(Vector_2D(bouncer_x,bouncer_y),Vector_2D(G_BOUNCER_SIZE+10,G_BOUNCER_SIZE));
        gScore = 0;
    }
    else
    {
        s = ps;
        
    }
    
    ui = new LevelUI(s);
    
    
    
    //HelperShip *hs = new HelperShip(Vector_2D(bouncer_x+100,bouncer_y),Vector_2D(G_BOUNCER_SIZE/2,G_BOUNCER_SIZE/2));
    //cout << hs->getLocalLocation().toString() << hs->getAbsoluteLocation().toString() << "\n";
    //s->addChild(hs);
    //cout << hs->getLocalLocation().toString() << hs->getAbsoluteLocation().toString() << "\n";
    
    //printf("Empty has no parent %d child has parent %d",s->hasParent(), hs->hasParent());
                                    
    
    loadWave(currentWave);
    
    G_Handler->add(s);
    
    
  //  G_Handler->add(hs);

}

bool Level::loadWave(int waveID)
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
                Vector_2D loc(G_SCREEN_W*x/100,G_SCREEN_H*y/100);
                enemyShip *e = new enemyShip(loc,name);
                swarmContainer->addChild(e);
                G_Handler->add(e);
                std::cout << "hi" << e->getAbsoluteLocation().toString();
            }
            
            fprintf(stderr, "%s\n", lua_tostring(LevelState, -1));
         //   cout << tab;
        } else {
            std::cout << "can't find table";
            return false;
        }
    }
    
    PowerUp *p = new PowerUp(Vector_2D(700,500),Vector_2D(-5,5),0);
    G_Handler->add(p);
    
    std::cout << "end of spawn wave\n";
    return true;
}
void Level::draw(ALLEGRO_DISPLAY *display)
{
    
    G_Handler->draw(display);
    std::string levID = itos(levelID);
    al_draw_text(font, color, 0, 0, NULL, levID.c_str());
}


void Level::update()
{
  
    G_Handler->update();
    G_Collider->update();
  
    
    if(s->hp <= 0)
        nextLevel = 0;
    if (swarmContainer->getNumberOfChildren() == 0)
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

void Level::handleKeyboardEvent(ALLEGRO_EVENT ev)
{
    if (key[KEY_SPACE] && ev.keyboard.keycode == ALLEGRO_KEY_SPACE)
        s->fire();
}

void Level::handleMouseEvent(ALLEGRO_EVENT ev)
{
    
}
