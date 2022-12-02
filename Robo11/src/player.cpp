
#include <cmath>
#include <sstream>
#include <bits/stdc++.h> 
#include "player.h"
#include "parser.h"
#include "constants.h"

using namespace std;

Player::Player()
{
    this->id = " ";
    this->position.x=Constants::NORMALIZEX;
    this->position.y=Constants::NORMALIZEY;
    this->target.x=Constants::NORMALIZEX;
    this->target.y=Constants::NORMALIZEY;
}

Player::Player(string id)
{
    this->id = id;
    this->position.x=Constants::NORMALIZEX;
    this->position.y=Constants::NORMALIZEY;
    this->target.x=Constants::NORMALIZEX;
    this->target.y=Constants::NORMALIZEY;
}

Player::~Player(){}

objectTypes Player::getType()
{
    return objectTypes::Player;
}

void Player::setTarget(Vector2 &t)
{
    this->target.x = t.x;
    this->target.y = t.y;
}

Vector2 Player::getTarget()
{
    return this->target;
}

void Player::limitTarget(int min_x, int min_y,int max_x, int max_y)
{
    if (this->target.x < min_x)
    {
        this->target.x = min_x;
    }else if (this->target.x > max_x)
    {
        this->target.x = max_x;
    }
    
    if (this->target.y < min_y)
    {
        this->target.y = min_y;
    }else if (this->target.y > max_y)
    {
        this->target.y = max_y;
    }
}

bool Player::kickingArea(shared_ptr<Ball> &b)
{
    Vector2 up(Constants::GOALX,Constants::GOALUPY);
    Vector2 down(Constants::GOALX,Constants::GOALDOWNY);
    Vector2 p_up,p_down;
    
    if(b->isLeftFront()==true && b->isInGoal()==false && Constants::GOALX != b->position.x)
    {
    p_up.x = b->position.x-Constants::KICKAREA;
    p_down.x = p_up.x;
    //p_up.y = b->position.y+Constants::KICKAREA*(down.y-b->position.y)/(down.x-b->position.x);
    p_up.y = b->position.y+Constants::KICKAREA*(b->position.y-Constants::GOALDOWNY)/(Constants::GOALX-b->position.x);
    //p_down.y = b->position.y-Constants::KICKAREA*(down.y-b->position.y)/(down.x-b->position.x);
    p_down.y = p_up.y-(Constants::GOALUPY-Constants::GOALDOWNY)*Constants::KICKAREA/(Constants::GOALX-b->position.x);
    cout <<"ball point "<< b->position.x << "," << b->position.y <<endl;
    cout <<"up point "<< p_up.x << "," << p_up.y <<endl;
    cout <<"down point "<< p_down.x << "," << p_down.y <<endl;
        if (this->position.isInTriangle(b->position,p_down,p_up,this->position)==true)
        {
            return true;
        }else{
            return false;
        }
    }else if(b->isRightFront()==true && b->isInGoal()==false && down.x != b->position.x)
    {
    p_up.x = b->position.x-Constants::KICKAREA;
    p_down.x = p_up.x;   
    p_down.y = b->position.y-Constants::KICKAREA*(Constants::GOALUPY-b->position.y)/(Constants::GOALX-b->position.x);
    p_up.y = b->position.y-Constants::KICKAREA*(Constants::GOALDOWNY-b->position.y)/(Constants::GOALX-b->position.x);
    cout <<"ball point "<< b->position.x << "," << b->position.y <<endl;
    cout <<"up point "<< p_up.x << "," << p_up.y <<endl;
    cout <<"down point "<< p_down.x << "," << p_down.y <<endl;
        if (this->position.isInTriangle(b->position,p_down,p_up,this->position)==true)
        {
            return true;
        }else{
            return false;
        }
    }

}

Vector2 Player::readyToKick(shared_ptr<Ball> &b)
{
    Vector2 goal(Constants::FIELDX,Constants::FIELDY/2);
    
    // double d_ballToDoor = sqrt(pow((goal.x-b.x),2) + pow((goal.y-b.y),2));
    // target.y= static_cast<int>(b.y-200*(b.y-goal.y)/d_ballToDoor);
    if(b->getFound()==true && b->isInGoal()==false && goal.x != (b->position.x))
    {
        Vector2 target; 
        float k;
        k = ((float)(goal.y-b->position.y))/(float)(goal.x -(b->position.x));
        target.x = (int)(-Constants::KICKDISTANCE/sqrt(k*k+1)+b->position.x);  
        if(k<0)
        {
            target.y = (int)(-Constants::KICKDISTANCE*k/sqrt(k*k+1)+b->position.y);
        }else if (k>0)
        {
            target.y = (int)(-Constants::KICKDISTANCE*k/sqrt(k*k+1)+b->position.y);
        }  
        
        cout<<"ready to kick ponit "<<target.x << "," << target.y <<endl; 
        return target;  
    }else
    {
        return b->position;
    }
}

void Player::initKalmanFilter()
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

Vector2 Player::getNextPosition()
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
