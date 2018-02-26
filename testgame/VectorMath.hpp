//
//  VectorMath.hpp
//  testgame
//
//  Created by Sasha Han on 2/25/18.
//  Copyright © 2018 __. All rights reserved.
//
#pragma once

#include <sstream>


std::string itos(int x);

class Vector_2D
{
public:
    Vector_2D()
    {
        x = 0;
        y = 0;
    }
    Vector_2D(int ix, int iy)
    {
        x = ix;
        y = iy;
    }
    ~Vector_2D()
    {
        
    }
    
    
    std::string toString()
    {
        std::string ret;
        std::string sx = itos(x);
        std::string sy = itos(y);
        ret = "(" + sx + "," + sy + ")";
        return ret;
    }
    
    
    
    float x;
    float y;
    
    
};

Vector_2D Add2DV(Vector_2D v1, Vector_2D v2);
Vector_2D Sub2DV(Vector_2D v1, Vector_2D v2);
float Dot2DV(Vector_2D v1, Vector_2D v2);


class Vector_3D
{
public:
    Vector_3D()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    Vector_3D(int ix, int iy, int iz)
    {
        x = ix;
        y = iy;
        z = iz;
    }
    ~Vector_3D()
    {
        
    }
    
    
    std::string toString()
    {
        std::string ret;
        std::string sx = itos(x);
        std::string sy = itos(y);
        std::string sz = itos(z);
        ret = "(" + sx + "," + sy + "," + sz +  ")";
        return ret;
    }
    
    
    
    int x;
    int y;
    int z;
    
    
};

Vector_3D Add3DV(Vector_3D v1, Vector_3D v2);
Vector_3D Sub3DV(Vector_3D v1, Vector_3D v2);
float Dot2DV(Vector_3D v1, Vector_3D v2);

