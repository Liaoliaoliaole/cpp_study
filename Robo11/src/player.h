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

    
    Vectr AMstadByPass(Vectr &b);
    Vectr AMstadByKick(Vectr &b);
    Vectr readyToKick(Vectr &b);
    string sendCords(Vectr &v);

};
#endif

