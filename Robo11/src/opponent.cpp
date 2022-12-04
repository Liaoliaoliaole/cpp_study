
#include "ball.h"
#include "opponent.h"


using namespace std;
Opponent::Opponent()
{}

Opponent::Opponent(string id)
{
    this->id = id;
    this->position.x=2100;
    this->position.y=1650;
    this->target.x=0;
    this->target.y=0;
}

Opponent::~Opponent()
{}

objectTypes Opponent::getType(){
    return objectTypes::Opponent;
}

Vector2 Opponent::getTarget()
{
    Vector2 t;
    //calculate the opponent moving derection
    return t;
}

void Opponent::initKalmanFilter()
{
  
}

Vector2 Opponent::getNextPosition()
{

  Vector2 r(0,0);
  return r;
}
