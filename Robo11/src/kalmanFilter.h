#ifndef _MYKALMAN_H
#define _MYKALMAN_H
/*Eigen3 is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms.*/
#include <eigen3/Eigen/Dense>
#include "vector2.h"

class KalmanFilter
{
private:
    bool is_initialized; 
    Eigen::VectorXd x; //old state
    //Eigen::VectorXd z; //new state

    //Eigen::VectorXd u;//acceleration
    Eigen::MatrixXd F;//time interval
    Eigen::MatrixXd P;//coveriance
    Eigen::MatrixXd H;//measurement matrix
    Eigen::MatrixXd R;//measurement noise covariance
    Eigen::MatrixXd Q;//process noise covariance
public:
    KalmanFilter(){ is_initialized = false;};
    ~KalmanFilter(){}
    // get state vector
    Eigen::VectorXd GetX()
    {
        return this->x;
    }
    
    bool isInitialized();
    void initialization(Eigen::VectorXd x_in);
    void SetF();
    void SetP();
    void SetQ();
    void SetH();
    void SetR();
    void prediction();
    void measurementUpdate(const Eigen:: VectorXd &z);
};
#endif