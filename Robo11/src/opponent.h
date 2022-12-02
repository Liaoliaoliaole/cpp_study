#ifndef OPPONENT_H
#define OPPONENT_H

#include "object.h"
#include "kalmanFilter.h"

using namespace std;

class Opponent: public Object{

public:
    Opponent();
    Opponent(string id);
    ~Opponent();

    objectTypes getType();
    Vector2 getTarget();
    void initKalmanFilter();
    Vector2 getNextPosition();

};
#endif
