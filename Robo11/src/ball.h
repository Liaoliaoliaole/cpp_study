#ifndef BALL_H
#define BALL_H

#include "object.h"

using namespace std;

class Ball: public Object{

public:
    bool found;

    static Eigen::MatrixXd A; // System dynamics matrix
    static Eigen::MatrixXd C; // Output matrix
    static Eigen::MatrixXd Q; // Process noise covariance
    static Eigen::MatrixXd R; // Measurement noise covariance
    static Eigen::MatrixXd P; // Estimate error covariance

public:
    Ball();
    ~Ball();
    
    bool getFound();
    objectTypes getType();
    Vector2 getTarget();
    void initKalmanFilter();
    Vector2 getNextPosition();
    bool isInGoal();
    bool isLeftFront(); 
    bool isLeftBack();
    bool isRightFront();
    bool isRightBack();  
};

#endif