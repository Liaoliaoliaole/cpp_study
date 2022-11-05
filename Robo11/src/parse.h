#ifndef PARSE_H
#define PARSE_H

#include <memory>
#include"vectr.h"
#include "object.h"

class Parse{
public:

static void connectToServer(shared_ptr<Socket> sock);
static string readFromServer(shared_ptr<Socket> sock);
static void parseAndSetCords(string &str,vector<shared_ptr<Object>> &o);
//void toStepTarget(shared_ptr<Socket> sock,vector<shared_ptr<Object>> &os);
//void ToTarget(shared_ptr<Socket> sock,vector<shared_ptr<Object>> &os);
static void planToTarget(shared_ptr<Socket> sock,vector<shared_ptr<Object>> &os);
static vector<shared_ptr<Vectr>> circle_dance(int a, int b,int r);
};


#endif