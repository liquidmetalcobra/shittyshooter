//
//  gameobject.hpp
//  AllegroGame
//
//  Created by Sasha Han on 1/13/16.
//
//

#pragma once
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "globals.h"

class gameobject
{
public:
    gameobject()
    {
        this->x = 200;
        this->y = 200;
        this->size = 100;
        this->id = 0;
        visible = true;
        collisionClass = COLLISION_CLASS_NONE;
        markForDeath = false;
    };
    
    virtual ~gameobject(){
        
      //  std::cout << "GAME OBJECT DYING\n";
        
    };
    
    virtual void collide(gameobject *go);
    virtual void update();
    virtual void init();
    virtual void draw();
    virtual void destroy() = 0;
    
    float getX() { return x; }
    float getY() { return y; }
    float getWidth() { return w; }
    float getHeight() { return h; }
    
    bool getVisible() { return visible; }
    
    int getID() { return id; }
    int getSize() { return this->size; }
    
    collisionClasses getCollisionClass() { return collisionClass; }
    
    void setX(float newX) { x = newX; }
    void setY(float newY) { y = newY; }
    void setID(float newID) { id = newID; }
    void setVisible(bool newVisible) { visible = newVisible; }
    void setSize(int newSize) { size = newSize; }
    void setCollisionClass(collisionClasses newCollisionClass) { collisionClass = newCollisionClass; }
    
    bool markForDeath;
    
    
    
protected:
    bool visible;
    float x;
    float y;
    int w;
    int h;
    int size;
    int id;
    int resetCount;
    collisionClasses collisionClass;
    
};