//
//  enemyShip.cpp
//  testgame
//
//  Created by Sasha Han on 10/14/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "enemyShip.hpp"

bool enemyShip::init(string scriptName)
{
    ShipState = luaL_newstate();
    
    
    
    luaL_openlibs(ShipState);
    lua_pcall(ShipState, 0, 0, 0);
    std::cout << "before register\n";
    luabridge::getGlobalNamespace(ShipState)
    .beginClass<ship>("ship")
    //.addConstructor<void(*)(void)>()
  //  .addProperty("X", getX, setX)
  //  .addProperty("Y", &enemyShip::getY, &enemyShip::setY)
    .addFunction("move", &ship::move)
    .endClass()
    .deriveClass<enemyShip, ship> ("enemyShip")
    .endClass();
    
    printf("making a %s\n",scriptName.c_str());
    std::string fileLocation = G_ENEMY_SCRIPT_LOCATION + scriptName + ".lua";
    std::cout << luaL_dofile(ShipState, fileLocation.c_str());
    std::cout << "after register\n";
    
    luabridge::LuaRef table = luabridge::getGlobal(ShipState, scriptName.c_str());
    if (table.isTable()) {
        
        id = table["id"].cast<int>();
        firerate = table["fireRate"].cast<int>();
        hp = table["health"].cast<int>();
        hpMax = hp;
        spriteSize.x = table["width"].cast<int>();
        
        spriteSize.y = table["height"].cast<int>();
        std::cout << "before make func\n";
        updateFunc = std::make_shared<luabridge::LuaRef>(table["update"]);
        std::cout << "after make func\n";
    }
    else
        return false;
   
    count = 0;
    size.x = spriteSize.x;
    size.y = spriteSize.y;
    b = al_create_bitmap(size.x, size.y);
    cout << size.x << "\t" << size.y << "\n";
    al_set_target_bitmap(b);
    al_clear_to_color(al_map_rgb(55, 10, 123));
   
    return true;

}
void enemyShip::collide(gameobject *go)
{
    if (go->getID() != getID() && go->getID() >= 0)
    {
        hp-=10;
        if (hp<=0)
        {
            
            PowerUp *p = new PowerUp(location,Vector_2D(-5,5),rand()%(GAME_OBJECT_ID_POWERUP-GAME_OBJECT_ID_POWERUP_HEALTH));
            G_Handler->add(p);
            gScore += 100;
            markForDeath = true;
        }
    }
}



void enemyShip::update()
{
    
    
    if (count > firerate)
    {
        bulletGen->generateBullet(getAbsoluteLocation(), Vector_2D(-10, 0), getID());
        count = 0;
    }
    else
    {
        count++;
    }
    bulletGen->update();
    
    if (updateFunc) {
        try{
            
            (*updateFunc)(this, this);
        }
        catch (luabridge::LuaException const& e) {
            std::cout << "LuaException: " << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << "No Update Function";
    }
}

