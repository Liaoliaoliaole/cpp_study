
#include <cmath>
#include "player.h"

using namespace std;

Player::Player()
{
    this->id = " ";
    this->position.x=2100;
    this->position.y=1650;
}

Player::Player(string id)
{
    this->id = id;
    this->position.x=2100;
    this->position.y=1650;
}

Player::~Player(){}

Vectr Player::readyToKick(Vectr &b)
{
    Vectr goal(4800,1650);
    Vectr target; 
    // double d_ballToDoor = sqrt(pow((goal.x-b.x),2) + pow((goal.y-b.y),2));
    // target.y= static_cast<int>(b.y-200*(b.y-goal.y)/d_ballToDoor);
    // target.x= static_cast<int>(b.x-200*(b.x-goal.x)/d_ballToDoor);
    // target.y= static_cast<int>(1.2*b.y-160*2);
    // target.x= static_cast<int>(1.2*b.x-480*2);
    // if((b.x < goal.x-400 && (b.y < goal.y+400 && b.y > goal.y-400))
    //     || ((b.x>400 && (b.y < goal.y+400 && b.y > goal.y-400)))){
    double k= (b.y-goal.y)/(b.x-goal.x);
    target.x= (int)(-250/sqrt(k*k+1)+b.x);
    target.y = (int)(abs(250*k/sqrt(k*k+1)+b.y));
    //}
    return target;  
}

