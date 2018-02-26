//
//  LevelLoader.cpp
//  testgame
//
//  Created by Sasha Han on 12/10/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "LevelLoader.hpp"
void LevelLoader::init()
{
    
    
    
    currentLevel = 0;
    MainMenu *m = new MainMenu();
    Level *l1 = new Level(1);
    Level *l2 = new Level(2);
    Level *l3 = new Level(3);
    
    levels.push_back(m);
    levels.push_back(l1);
    levels.push_back(l2);
    levels.push_back(l3);
}
void LevelLoader::draw()
{
    levels[currentLevel]->draw();
}


void LevelLoader::update()
{
    
    
    if (levels[currentLevel]->levelComplete)
    {
        
        PlayerShip *s = levels[currentLevel]->s;
        int nextLevel = levels[currentLevel]->GetNextLevel();
        
        printf("Going from level %d to %d\n",currentLevel, nextLevel);
        levels[currentLevel]->levelComplete = false;
        levels[currentLevel]->SetNextLevel(currentLevel);
        currentLevel = nextLevel;
        levels[currentLevel]->load(s);
        
    }
    
    levels[currentLevel]->update();
}

void LevelLoader::handleKeyboardEvent(ALLEGRO_EVENT ev)
{
    levels[currentLevel]->handleKeyboardEvent(ev);
}

void LevelLoader::handleMouseEvent(ALLEGRO_EVENT ev)
{
    levels[currentLevel]->handleMouseEvent(ev);
}
