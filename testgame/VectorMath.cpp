//
//  VectorMath.cpp
//  testgame
//
//  Created by Sasha Han on 2/25/18.
//  Copyright © 2018 __. All rights reserved.
//

#include "VectorMath.hpp"


std::string itos(int x)
{
    
    std::stringstream ss;
    ss << x;//add number to the stream
    
    return ss.str();
}

Vector_2D Add2DV(Vector_2D v1, Vector_2D v2)
{
    
    Vector_2D ret(v1.x + v2.x,v1.y + v2.y);
    return ret;
}

Vector_2D Sub2DV(Vector_2D v1, Vector_2D v2)
{
    Vector_2D ret(v1.x - v2.x,v1.y - v2.y);
    return ret;
}
float Dot2DV(Vector_2D v1, Vector_2D v2)
{
    return v1.x*v2.x + v1.y*v2.y;
}



Vector_3D Add3DV(Vector_3D v1, Vector_3D v2)
{
    Vector_3D ret(v1.x + v2.x,v1.y + v2.y,v1.z + v2.z);
    return ret;
}
Vector_3D Sub3DV(Vector_3D v1, Vector_3D v2)
{
    Vector_3D ret(v1.x - v2.x,v1.y - v2.y,v1.z - v2.z);
    return ret;
    
}
float Dot3DV(Vector_3D v1, Vector_3D v2)
{
    return v1.x*v2.x + v1.z*v2.z + v1.z*v2.z;
}
Vector_3D Cross3DV(Vector_3D v1, Vector_3D v2)
{
    Vector_3D ret(v1.y*v2.z - v1.z*v2.y,v1.z*v2.x - v1.x*v2.z,v1.x*v2.y - v1.y*v2.x);
    return ret;
    
}