#ifndef OBJECT_H
#define OBJECT_H

#include "vector2.h"

enum class objectTypes{None,Ball,Player,Opponent};

class Object
{
public:
    Vector2 position;
    Vector2 target;
    string id;
    objectTypes type;

public:
    Object();
    Object(string id);
    ~Object();
    
    virtual objectTypes getType()=0;
    virtual Vector2 getTarget()=0;
    void setPosition(Vector2 &p);
    string getID();

};



#endif