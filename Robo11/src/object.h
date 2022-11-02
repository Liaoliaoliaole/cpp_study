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
    //Vectr limitRange(Vectr &range);
    //virtual void move(map<string,Vectr> cords,Vectr &b, shared_ptr<Socket> &sock)=0;
    virtual Vectr readyToKick(Vectr &b)=0;

    void setPosition(Vectr pos);
    Vectr getPosition();
    void setID(string id);
    string getID();

};



#endif