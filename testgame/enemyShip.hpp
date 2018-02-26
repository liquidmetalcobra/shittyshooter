//
//  enemyShip.hpp
//  testgame
//
//  Created by Sasha Han on 10/14/17.
//  Copyright © 2017 __. All rights reserved.
//

#pragma once

#include "iostream" 

#include "BulletFactory.hpp"
#include "Collider.hpp"
#include "ship.hpp"
#include "PowerUp.hpp"
class enemyShip : public ship {
public:
    
    enemyShip(int iX, int iY,string scriptName) : ship(iX,iY,20,20)
    {
        
        updateFunc = nullptr;
        
        init(scriptName);
        
        
        
        
    }
    ~enemyShip()
    {
     //   std::cout << "enemy ship dying\n";
    }
    
    
    void update();
    void collide(gameobject *go);
    std::shared_ptr<luabridge::LuaRef> updateFunc;
    
    
private:
    bool init(string scriptName);
    int count;
    int firerate;
    lua_State* ShipState;
};