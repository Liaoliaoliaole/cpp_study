#ifndef BALL_H
#define BALL_H

#include "object.h"

using namespace std;

class Ball: public Object{

public:
    bool found;

public:
    Ball();
    ~Ball();
    
    bool getFound();
    objectTypes getType();
    Vector2 getTarget();
    void initKalmanFilter();
    Vector2 getNextPosition();
    bool isInGoal();
    bool isLeftFront(); 
    bool isLeftBack();
    bool isRightFront();
    bool isRightBack();  
};

#endif