#ifndef STRATEGY_H
#define STRATEGY_H

#include"ball.h"
#include "player.h"
#include "opponent.h"

using namespace std;

class Strategy
{
public:

static void BackDefanceL(shared_ptr<Socket> sock,shared_ptr<Ball> &b,shared_ptr<Player> &p);
static void BackDefanceR(shared_ptr<Socket> sock,shared_ptr<Ball> &b,shared_ptr<Player> &p);
static void AttackingMidfield(shared_ptr<Socket> sock,shared_ptr<Ball> &b,shared_ptr<Player> &p);
};

#endif