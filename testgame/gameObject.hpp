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
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "globals.h"

class gameobject
{
public:
    gameobject()
    {
        
        
        this->id = 0;
        parent = NULL;
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
    float getLocalX() { return localLocation.x; }
    float getLocalY() { return localLocation.y; }
    float getWidth() { return size.x; }
    float getHeight() { return size.y; }
    Vector_2D getAbsoluteLocation() { return (parent != NULL) ? Add2DV(parent->getAbsoluteLocation(), localLocation) : location; }
    Vector_2D getLocation() { return location; }
    Vector_2D getSize() { return size; }
    Vector_2D getLocalLocation() { return localLocation; }
    
    bool getVisible() { return visible; }
    
    gameobject * getParent() { return parent; }
    
    int getID() { return id; }
    unsigned long getNumberOfChildren() { return _children.size(); }
    
    collisionClasses getCollisionClass() { return collisionClass; }
    
    void setX(float newX) { location.x = newX; }
    void setY(float newY) { location.y = newY; }
    void setLocalX(float newX) { localLocation.x = newX; }
    void setLocalY(float newY) { localLocation.y = newY; }
    void setID(float newID) { id = newID; }
    void setVisible(bool newVisible) { visible = newVisible; }
    
    void setCollisionClass(collisionClasses newCollisionClass) { collisionClass = newCollisionClass; }
    
    void Transform(Vector_2D delta);
    
    bool markForDeath;
    
    void removeAllChildren();
    void addChild(gameobject * newChild);
    void removeChild(gameobject *child);
    void removeParent() { if (parent != NULL) parent->removeChild(this); }
    bool isParentOf(gameobject * child);
    bool isChildOf(gameobject * parent);
    bool hasParent() { return parent != NULL; }
    
protected:
    bool visible;
    Vector_2D location;
    Vector_2D localLocation;
    Vector_2D size;
    
    int id;
    int resetCount;
    collisionClasses collisionClass;
    gameobject *parent;
    std::vector<gameobject*> _children;
    
    
};