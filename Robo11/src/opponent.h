#ifndef OPPONENT_H
#define OPPONENT_H

#include "object.h"

using namespace std;

class Opponent: public Object{

public:
    Opponent();
    Opponent(string id);
    //Opponent(map<string,Vectr> cords);
    ~Opponent();

};
#endif
