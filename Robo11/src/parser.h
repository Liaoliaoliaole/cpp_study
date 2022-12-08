#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include "ball.h"
#include "player.h"
#include "opponent.h"

class Parser{
public:
static vector<shared_ptr<Object>> initObjects();
static void parse(string &str,vector<shared_ptr<Object>> &os);
static string concatenate(vector<shared_ptr<Object>> &os);
};


#endif