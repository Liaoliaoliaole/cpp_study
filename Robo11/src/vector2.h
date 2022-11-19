#ifndef VECTR_H
#define VECTR_H

#include <iostream>
#include "socket.h"

class Vector2
{
public:
    int x, y;

public:
    Vector2(int i = 0, int j = 0);
    Vector2(const Vector2 &v);
    ~Vector2();
    
    Vector2 minus(Vector2 &u, Vector2 &v);
    double getMagnitude();
    double distanceToV2(Vector2 &v);

    double product(Vector2 &p1,Vector2 &p2,Vector2 &p3);
    bool isInTriangle(Vector2 p1,Vector2 p2,Vector2 p3,Vector2 o);
}; 
#endif