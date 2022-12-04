#include "object.h"

int Object::n = 6;//x:position,velocity,acceleration;y:p,v,a
int Object::m = 2;//only position will be mesured
float Object::dt = Constants::T;

Object::Object()
{
    this->id = "";
    this->position.x = 0;
    this->position.y = 0;
    objectTypes type = objectTypes::None;
}

Object::Object(string id)
{
    this->id = id;
    this->position.x = 0;
    this->position.y = 0;
    this->target.x =0;
    this->target.y =0;
    this->nextPosition.x =0;
    this->nextPosition.y =0;    
    objectTypes type = objectTypes::None;
}

Object::~Object(){
}

void Object::setPosition(Vector2 &p)
{
  this->position.x = p.x;
  this->position.y = p.y;
}

string Object::getID() 
{
  return this->id;
}


