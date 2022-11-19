#include "object.h"

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

