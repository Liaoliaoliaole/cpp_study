#include "kalmanFilter.h"
#include "constants.h"

    // get flag of initialization
    bool KalmanFilter::isInitialized()
    {
        return is_initialized;
    }

    // initialize kalman filter
    void KalmanFilter::initialization(Eigen::VectorXd x_in)
    {
        this->x = x_in;
        is_initialized = true;
    }

    void KalmanFilter::SetF()
    {
        Eigen::MatrixXd F_in(4, 4);
        F_in << 1.0, 0.0, Constants::T, 0.0,
                0.0, 1.0, 0.0, Constants::T,
                0.0, 0.0, 1.0, 0.0,
                0.0, 0.0, 0.0, 1.0;
        this->F = F_in;
    }

    void KalmanFilter::SetP()
    {
        Eigen::MatrixXd P_in(4, 4);
        P_in << Constants::PS, 0.0, 0.0, 0.0,
                0.0, Constants::PS, 0.0, 0.0,
                0.0, 0.0, Constants::PV, 0.0,
                0.0, 0.0, 0.0, Constants::PV,0.0;
        this->P= P_in;
    }

    void KalmanFilter::SetQ()
    {
        Eigen::MatrixXd Q_in(4, 4);
        Q_in << Constants::T, 0.0, 0.0, 0.0,
                0.0, Constants::T, 0.0, 0.0,
                0.0, 0.0, Constants::T, 0.0,
                0.0, 0.0, 0.0, Constants::T;
        this->Q = Q_in;
    }

    void KalmanFilter::SetH()
    {
        Eigen::MatrixXd H_in(2, 4);
        H_in << 1.0, 0.0, 0.0, 0.0,
                0.0, 1.0, 0.0, 0.0;
        this->H = H_in;
    }

    void KalmanFilter::SetR()
    {
        Eigen::MatrixXd R_in(2, 2);
        R_in << Constants::R, 0.0,
                0.0, Constants::R;
        this->R = R_in;
    }

    // predict state vector and state covariance matrix
    void KalmanFilter::prediction()
    {
        this->x = this->F * this->x/* +this->u */;
        Eigen::MatrixXd Ft = this->F.transpose();
        this->P = this->F * this->P * Ft + this->Q;
    }

    // update state vector and state covariance matrix
    void KalmanFilter::measurementUpdate(const Eigen:: VectorXd &z)
    {
        Eigen::VectorXd y = z - this->H * this->x;
        Eigen::MatrixXd S = this->H * this->P * this->H.transpose() + this->R;
        // Kalman Gain
        Eigen::MatrixXd K = this->P * this->H.transpose() * S.inverse();
        // estimate state vector
        this->x = this->x + K * y;
        int size = this->x.size();
        Eigen::MatrixXd I = Eigen::MatrixXd::Identity(size, size);
        // update state covariance matrix
        this->P = (I - K * this->H) * this->P;
    }