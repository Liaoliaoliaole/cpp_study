#ifndef PARSE_H
#define PARSE_H

#include <memory>
#include"vectr.h"
#include "object.h"


string readFromServer(shared_ptr<Socket> sock);
void update(string &str,vector<shared_ptr<Object>> &o);
//void connectToServer(shared_ptr<Socket> sock);
//void readFromServer(shared_ptr<Socket> sock, string buffer);
//map<string,Vectr> split(string &str);
vector<shared_ptr<Vectr>> circle_dance(int a, int b,int r);
//void printAllCords(map<string,Vectr> cords_map);

#endif