
#include "ball.h"
#include "opponent.h"

using namespace std;

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
    //calculate the opponent moving derection by kalman filter
    return t;
}
