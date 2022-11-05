#ifndef BALL_H
#define BALL_H

#include "object.h"

using namespace std;

class Ball: public Object{

public:
    bool found;

public:
    Ball();
    Ball(Vectr b,bool s);
    //Ball(map<string,Vectr> cords);
    ~Ball();
    bool getFound();
    void setFound(bool status);
    
};

#endif