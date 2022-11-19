#ifndef NETWORK_H
#define NETWORK_H

#include <memory>
#include <string>
#include "socket.h"
#include "player.h"

class Network
{
public:

static shared_ptr<Socket> connectToServer();
static string readFromServer(shared_ptr<Socket> &sock);
static void sendToServer(shared_ptr<Socket> &sock,string &ts);
};

#endif