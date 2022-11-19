#ifndef OPPONENT_H
#define OPPONENT_H

#include "object.h"

using namespace std;

class Opponent: public Object{

public:
    Opponent(string id);
    ~Opponent();

    objectTypes getType();
    Vector2 getTarget();

};
#endif
