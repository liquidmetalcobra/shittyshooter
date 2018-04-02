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
    std::cout << newChild->getAbsoluteLocation().toString();
    newChild->Transform(Sub2DV(newChild->location,this->location));
}
void gameobject::removeChild(gameobject * child)
{
    
    _children.erase(std::remove(_children.begin(), _children.end(), child), _children.end());
    child->parent = NULL;
    child->localLocation = Vector_2D(0,0);
    child->Transform(Add2DV(child->getLocalLocation(), this->location));
}
void gameobject::removeAllChildren()
{
    for ( int i = 0; i < _children.size(); i++)
    {
        _children[i]->parent = NULL;
        _children[i]->localLocation = Vector_2D(0,0);
        _children[i]->Transform(Add2DV(_children[i]->getLocalLocation(), this->location));
    }
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
    if (this->parent != NULL)
    {
       // std::cout << delta.toString() << localLocation.toString() << "\n";
        localLocation = Add2DV(localLocation, delta);
    }
    else
    {
        location = Add2DV(location, delta);
    }
    
    /*for (unsigned i=0; i < _children.size(); i++) {
        _children[i]->Transform(delta);
    }*/
}