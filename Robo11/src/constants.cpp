#include "constants.h"

const int Constants::FIELDX;
const int Constants::FIELDY;
const int Constants::GOALX;
const int Constants::GOALY;
const int Constants::GOALUPY;
const int Constants::GOALDOWNY;
const int Constants::GOALWIDTH;
const int Constants::ROBOSIZE;

const int Constants::OFFSET;
const int Constants::KICKDISTANCE;
const int Constants::KICKAREA;

const int Constants::BALL;
const int Constants::GOALKEEPER;
const int Constants::DEFENCERIGHT;
const int Constants::DEFENCELEFT;
const int Constants::ATTACKEL;
const int Constants::ATTACKER;

const int Constants::NORMALIZEX;
const int Constants::NORMALIZEY;

const float Constants::T=0.02f;
//Only the position of the point can be measured, but the speed of the point cannot be measured. 
//Therefore, for the covariance matrix of the lidar, for the position information, the measurement position is accurate and the uncertainty is low; 
//for the speed information, the uncertainty is high.
const float Constants::PS=1.0f;
const float Constants::PV=100.0f;
//Q has an impact on the entire system, but it is not too sure how much impact it has on the system. 
//This effect cannot be estimated by previous state transitions.
const float Constants::Q=1.0f;
//Usually provide by manufacture,A sensor that measures 100% exactly has a variance of σ ²= 0 (it does not exist).
const float Constants::R = 0.0f;