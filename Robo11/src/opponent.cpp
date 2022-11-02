
#include "ball.h"
#include "opponent.h"


using namespace std;

Opponent::Opponent()
{
    this->id = " ";
    this->position.x=2100;
    this->position.y=1650;
}

Opponent::Opponent(string id)
{
    this->id = id;
    this->position.x=2100;
    this->position.y=1650;
}
Opponent::~Opponent()
{}

Vectr Opponent::readyToKick(Vectr  &b)
{
    return b;
}