#ifndef STRATEGY_H
#define STRATEGY_H

#include"ball.h"
#include "player.h"
#include "opponent.h"

using namespace std;

class Strategy
{
public:
static void AttackerL(vector<shared_ptr<Object>> &os);
static void AttackerR(vector<shared_ptr<Object>> &os);
static void Defender(vector<shared_ptr<Object>> &os);
static void GoalKeeper(vector<shared_ptr<Object>> &os);
//static void Midfielder(vector<shared_ptr<Object>> &os);
};

#endif