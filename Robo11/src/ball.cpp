#include <cmath>
#include "ball.h"
#include "constants.h"


Ball::Ball(){
    this->id = "B";
    this->position.x =0;
    this->position.y =0;
    this->target.x=0;
    this->target.y=0;
    this->found = true;

}

Ball::~Ball(){
}

bool Ball::getFound() {
    if(this->position.x<=4800 && this->position.x>=0 && this->position.y<=3300 && this->position.y>=0)
    {
    return true;
    }else{
        return false;
    }
}
  
objectTypes Ball::getType(){
    return objectTypes::Ball;
}

Vector2 Ball::getTarget()
{
    Vector2 t;
    //calculate the ball moving derection by kalman filter
    return t;
}

bool Ball::isInGoal()
{
    if (pow((this->position.x-Constants::GOALX),2)+pow((this->position.x-Constants::GOALY/2),2)<=Constants::GOALWIDTH*Constants::GOALWIDTH)
    {
        return true;
    }else{
        return false;
    }
}

bool Ball::isLeftFront()
{
    if((this->position.x>=Constants::GOALX/4 && this->position.x<=Constants::GOALX) &&(this->position.y>=Constants::GOALY/2 && this->position.y<=Constants::GOALY))
    {
        return true;
    }else{
        return false;
    }
} 
bool Ball::isLeftBack()
{
     if((this->position.x>=0 && this->position.x<=Constants::GOALX/2) &&(this->position.y>=Constants::GOALY/2 && this->position.y<=Constants::GOALY))
    {
        return true;
    }else{
        return false;
    }
}
bool Ball::isRightFront()
{
     if((this->position.x>=Constants::GOALX/4 && this->position.x<=Constants::GOALX) &&(this->position.y>=0 && this->position.y<=Constants::GOALY/2))
    {
        return true;
    }else{
        return false;
    }
}
bool Ball::isRightBack()
{
     if((this->position.x>=0 && this->position.x<=Constants::GOALX/2) &&(this->position.y>=0 && this->position.y<=Constants::GOALY/2))
    {
        return true;
    }else{
        return false;
    }
}   