#ifndef OBJECT_H
#define OBJECT_H

#include "vectr.h"

class Object
{
public:
    Vectr position;
    string id;

public:
    Object();
    Object(string id);
    Object(string id,Vectr position);
    ~Object();

    void setPosition(Vectr pos);
    Vectr getPosition();
    void setID(string id);
    string getID();

};



#endif