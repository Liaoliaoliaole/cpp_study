#ifndef PARSE_H
#define PARSE_H

#include <memory>
#include"vectr.h"
#include "object.h"

//void connectToServer(shared_ptr<Socket> sock);
string readFromServer(shared_ptr<Socket> sock);
void parseAndSetCords(string &str,vector<shared_ptr<Object>> &o);
//void toStepTarget(shared_ptr<Socket> sock,vector<shared_ptr<Object>> &os);
//void ToTarget(shared_ptr<Socket> sock,vector<shared_ptr<Object>> &os);
void planToTarget(shared_ptr<Socket> sock,vector<shared_ptr<Object>> &os);

vector<shared_ptr<Vectr>> circle_dance(int a, int b,int r);


#endif