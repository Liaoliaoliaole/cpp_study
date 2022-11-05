#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include "ball.h"

using namespace std;

class Player: public Object{

public:
    Player();
    Player(string id);
    ~Player();

    Vectr readyToKick(Vectr &b);
    string sendCords();

};
#endif

