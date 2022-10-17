#ifndef POINT_H
#define POINT_H
#include<iostream>
#include"socket.h"

class Point
{
private:
    int x, y;
public:
    Point(int i = 0, int j = 0) {
        x = i;  y = j;
    }
    string display()
    {
    return to_string(x) + "," + to_string(y) + "\n";
    }
}; 
#endif

