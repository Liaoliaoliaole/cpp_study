#ifndef OBJECT_H
#define OBJECT_H

#include "vector2.h"
#include "kalmanFilter.h"

enum class objectTypes{None,Ball,Player,Opponent};

class Object
{
public:
    Vector2 position;
    Vector2 target;
    Vector2 nextPosition;
    string id;
    KalmanFilter kf;
    objectTypes type;

public:
    Object();
    Object(string id);
    ~Object();

    void setPosition(Vector2 &p);
    string getID();
    
    virtual objectTypes getType()=0;
    virtual Vector2 getTarget()=0;
    virtual void initKalmanFilter()=0;
    virtual Vector2 getNextPosition()=0;

};



#endif