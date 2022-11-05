#include "object.h"

Object::Object()
{
    this->id = "";
    this->position.x = 0;
    this->position.y = 0;
}

Object::Object(string id)
{
    this->id = id;
    this->position.x = 0;
    this->position.y = 0;
}


Object::Object(string id, Vectr position)
{
    this->id = id;
    this->position.x = position.x;
    this->position.y = position.y;
}

Object::~Object(){
}

Vectr Object::getPosition()
{
  return this->position;
} 
void Object::setPosition(Vectr pos)
{
  this->position.x = pos.x;
  this->position.y = pos.y;
}
void Object::setID(string id)
{
  this->id=id;
}
string Object::getID() 
{
  return this->id;
}

