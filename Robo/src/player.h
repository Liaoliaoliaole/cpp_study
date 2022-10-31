#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"

using namespace std;

class Player: public Object{

public:
    Player();
    Player(string id);
    //Player(map<string,Vectr> cords);
    ~Player();

    //void move(map<string,Vectr> cords, Vectr &b, shared_ptr<Socket> &sock);

};
#endif

