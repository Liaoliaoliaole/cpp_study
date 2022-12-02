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
    //calculate the ball moving derection
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

void Ball::initKalmanFilter()
{
  Eigen::VectorXd x_in(4, 1);
  x_in << this->position.x,this->position.y,0.0,0.0;
  cout << "-----------------Kalman filter input Sx is: " << x_in(0)<< ", output Sy is: " << x_in(1) << std::endl;
  if(!this->kf.isInitialized()){
  this->kf.initialization(x_in);
  /*Only the position of the ball can be measured, the speed cannot be measured. 
    Therefore, for the covariance matrix setup:
    for the position information, it is accurate and the uncertainty is low, set to 1.0; 
    for the speed information, the uncertainty is high, set to 100.*/
  this->kf.SetP(1.0,100.0);
  /*Q has an impact on the entire system, but it is not too sure how much impact it has on the system. 
    This effect cannot be estimated by previous state transitions.*/
  this->kf.SetQ(1.0);
  this->kf.SetH(1.0);
   /*Usually provide by sensor anufacture.
   A sensor that measures 100% exactly has a variance of σ ²= 0 (it does not exist).*/
  this->kf.SetR(0.0); 
  kf.SetF(); 
  }  
}

Vector2 Ball::getNextPosition()
{
  // predict state vector x and state covariance matrix P
  this->kf.prediction();
  // update state vector x and state covariance matrix P
  Eigen::VectorXd z(2,1);
  z << this->nextPosition.x, this->nextPosition.y;
  this->kf.measurementUpdate(z);
  Eigen::VectorXd x_out(4,1);
  x_out = this->kf.GetX();
  cout << "-----------------Kalman filter output Sx is: " << x_out(0)<< ", output Sy is: " << x_out(1) << std::endl;
  Vector2 r(x_out(0),x_out(1));
  return r;
}