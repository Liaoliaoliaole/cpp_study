#ifndef VECTR_H
#define VECTR_H
#include<iostream>
#include<cmath>
#include"socket.h"

class Vectr
{
public:
    int x, y;

public:
    Vectr(int i = 0, int j = 0);
    ~Vectr();

    int getX();
    int getY();
    void set(double x, double y);
    
    Vectr minus(Vectr &u, Vectr &v);
    double magnitude();
    void multiply(double r);
    double distanceToV2(Vectr &v);
    double setMagnitude(double newM);
    Vectr zeroVector();
    string printToCords();


}; 
#endif