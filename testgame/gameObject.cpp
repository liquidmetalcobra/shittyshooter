//
//  gameObject.cpp
//  testgame
//
//  Created by Sasha Han on 10/14/17.
//  Copyright © 2017 __. All rights reserved.
//

#include "gameObject.hpp"


void gameobject::collide(gameobject *go)
{
 //      std::cout << "oops";
}

void gameobject::update()
{
}
void gameobject::draw()
{
}
void gameobject::init()
{
    
}
void gameobject::destroy()
{
    
}
void gameobject::addChild(gameobject * newChild)
{
    
    _children.push_back(newChild);
    newChild->parent = this;
}
void gameobject::removeChild(gameobject * child)
{
    
    _children.erase(std::remove(_children.begin(), _children.end(), child), _children.end());
    child->parent = NULL;
}
void gameobject::removeAllChildren()
{
    _children.clear();
}

bool  gameobject::isParentOf(gameobject * child)
{
    std::vector<gameobject *>::iterator it = std::find(_children.begin(), _children.end(), child);
    if (it == _children.end())
        return false;
    return true;
    
}
bool  gameobject::isChildOf(gameobject * parent)
{
    if (this->parent == parent)
        return true;
    return false;
}

void gameobject::Transform(Vector_2D delta)
{
    location = Add2DV(location, delta);
    for (unsigned i=0; i < _children.size(); i++) {
        _children[i]->Transform(delta);
    }
}