//
//  gameobject.hpp
//  AllegroGame
//
//  Created by Sasha Han on 1/13/16.
//
//

#pragma once
#include <iostream>
#include <vector>
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
    
    float getX() { return location.x; }
    float getY() { return location.y; }
    float getWidth() { return size.x; }
    float getHeight() { return size.y; }
    
    bool getVisible() { return visible; }
    
    int getID() { return id; }
    
    
    collisionClasses getCollisionClass() { return collisionClass; }
    
    void setX(float newX) { location.x = newX; }
    void setY(float newY) { location.y = newY; }
    void setID(float newID) { id = newID; }
    void setVisible(bool newVisible) { visible = newVisible; }
    
    void setCollisionClass(collisionClasses newCollisionClass) { collisionClass = newCollisionClass; }
    
    bool markForDeath;
    
    void addChild(gameobject * newChild);
    
protected:
    bool visible;
    float x;
    float y;
    Vector_2D location;
    Vector_2D size;
    int w;
    int h;
    
    int id;
    int resetCount;
    collisionClasses collisionClass;
    gameobject *parent;
    std::vector<gameobject*> _children;
    
    
};