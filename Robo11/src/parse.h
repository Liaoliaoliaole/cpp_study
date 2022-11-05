#ifndef PARSE_H
#define PARSE_H

#include <memory>
#include "object.h"

class Parse{
public:

static void connectToServer(shared_ptr<Socket> sock);
static string readFromServer(shared_ptr<Socket> sock);
static void parseAndSetCords(string &str,vector<shared_ptr<Object>> &o);
static vector<shared_ptr<Vectr>> circle_dance(int a, int b,int r);
};


#endif