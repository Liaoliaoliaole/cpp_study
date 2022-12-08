#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include "ball.h"

using namespace std;

class Player: public Object{
private:
    Vector2 target;
    
public:
    Player();
    Player(string id);
    ~Player();

    objectTypes getType();
    void setTarget(Vector2 &t);
    Vector2 getTarget();

    Vector2 readyToKick(shared_ptr<Ball> &b);
    void limitTarget(int min_x, int min_y,int max_x, int max_y);
    bool kickingArea(shared_ptr<Ball> &b);


};
#endif

