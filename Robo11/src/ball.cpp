#include <cmath>
#include "ball.h"
#include "constants.h"

Eigen::MatrixXd Ball::A(n,n); // System dynamics matrix
Eigen::MatrixXd Ball::C(m,n); // Output matrix
Eigen::MatrixXd Ball::Q(n,n); // Process noise covariance
Eigen::MatrixXd Ball::R(m,m); // Measurement noise covariance
Eigen::MatrixXd Ball::P(n,n); // Estimate error covariance 

Ball::Ball(){
    this->id = "B";
    this->nextPosition.x =0;
    this->nextPosition.y =0;
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
    //CA model of discrete uniform acceleration motion
    //x_in [x,vx,ax,y,vy,ay]
    A << 1, dt, 0.5*dt*dt, 0, 0, 0, 
         0, 1, dt, 0, 0, 0,
         0, 0, 1, 0, 0, 0,
         0, 0, 0, 1, dt, 0.5*dt*dt,
         0, 0, 0, 0, 1, dt,
         0, 0, 0, 0, 0, 1;
    C << 0.5*dt*dt, 0,
         dt, 0,
         1, 0,
         0, 0.5*dt*dt,
         0, dt,
         0, 1;
    Q << 0.05, 0.05, 0, 0, 0, 0,
         0.05, 0.05, 0 ,0, 0, 0,
         0, 0, 0, 0, 0, 0,
         0, 0, 0, 0.05, 0.05, 0,
         0, 0, 0, 0.05, 0.05, 0,
         0, 0, 0, 0, 0 , 0 ;
    R << 5,5,
         5,5;
    P << 0.1, 0.1, 0.1, 0, 0, 0,
         0.1, 100, 10, 0, 0, 0,
         0.1, 10, 100, 0, 0, 0,
         0, 0, 0, 0.1, 0.1, 0.1,
         0, 0, 0, 0.1, 100, 10, 
         0, 0, 0, 0.1, 10, 100;
  
    KalmanFilter kf(dt,A, C, Q, R, P);
    this->kf=kf;
    Eigen::VectorXd x_in(n);
    double t = 0;
    //x_in [x,vx,ax,y,vy,ay]
    x_in << this->position.x,0,0,this->position.y,0,0;
    cout << "-----------------Kalman filter input Sx is: " << x_in(0)<< ", output Sy is: " << x_in(3) << std::endl;
    this->kf.init(t, x_in);
}

Vector2 Ball::getNextPosition()
{
  Eigen::VectorXd y(m);
  float t = this->kf.time();
  std::cout << "t = " << kf.time() << ", " << "x_hat[0]: " << kf.state().transpose() << std::endl;
  //for(int i = 0; i < 30; i++) {
    t += dt;
    y << this->nextPosition.x,this->nextPosition.y;
    kf.update(y);
    std::cout << "t = " << t << ", " << "y = " << y.transpose()
        << ", x_hat = " << kf.state().transpose() << std::endl;
  Vector2 r(y(0),y(1));
  return r;
//}
}

// void Ball::initKalmanFilter()
// {
//   Eigen::VectorXd x_in(4, 1);
//   x_in << this->position.x,this->position.y,0.0,0.0;
//   cout << "-----------------Kalman filter input Sx is: " << x_in(0)<< ", output Sy is: " << x_in(1) << std::endl;
// //   if (!this->kf.isInitialized())
// //   {
//       this->kf.initialization(x_in);
//       /*Only the position of the ball can be measured, the speed cannot be measured.
//         Therefore, for the covariance matrix setup:
//         for the position information, it is accurate and the uncertainty is low, set to 1.0;
//         for the speed information, the uncertainty is high, set to 100.*/
//       this->kf.SetP(1.0, 100.0);
//       /*Q has an impact on the entire system, but it is not too sure how much impact it has on the system.
//         This effect cannot be estimated by previous state transitions.*/
//       this->kf.SetQ(1.0);
//       this->kf.SetH(1.0);
//       /*Usually provide by sensor anufacture.
//       A sensor that measures 100% exactly has a variance of σ ²= 0 (it does not exist).*/
//       this->kf.SetR(0.0);
//       this->kf.SetF();
// //    }
// }

// Vector2 Ball::getNextPosition()
// {
//   // predict state vector x and state covariance matrix P
//   this->kf.prediction();
//   // update state vector x and state covariance matrix P
//   Eigen::VectorXd z(2,1);
//   z << this->nextPosition.x, this->nextPosition.y;
//   this->kf.measurementUpdate(z);
//   Eigen::VectorXd x_out(4,1);
//   x_out = this->kf.GetX();
//   cout << "-----------------Kalman filter output Sx is: " << x_out(0)<< ", output Sy is: " << x_out(1) << std::endl;
//   Vector2 r(x_out(0),x_out(1));
//   return r;
// }