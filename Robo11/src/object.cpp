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

Vector2 Object::getPosition()
{
  return this->position;
}

void Object::setX(int x)
{
  this->position.x=x;
}

void Object::setY(int y){
  this->position.y=y;
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

