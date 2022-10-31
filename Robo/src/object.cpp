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

// Vectr Object::limitRange(Vectr &range)
// {
//     auto limitedTarget =  Vectr(range);
//     if (limitedTarget.x < -200) {
//       limitedTarget.x = -200;
//     } else if (limitedTarget.x > 5000) {
//       limitedTarget.x = 5000;
//     } 
//     if (limitedTarget.y < -200) {
//       limitedTarget.y = -200;
//     } else if (limitedTarget.y > 3500) {
//       limitedTarget.y = 3500;
//     } 
//     return limitedTarget;
// }

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

