#include "network.h"
#include "player.h"
#include "opponent.h"

using namespace std;

shared_ptr<Socket> Network::connectToServer()
{
    string ip = "localhost";
    string port = "10000";
    auto sock = make_shared<Socket>(AF_INET,SOCK_STREAM,0);
    sock->connect(ip, port);
    return sock;
}

string Network::readFromServer(shared_ptr<Socket> &sock)
{
    string buffer;
    sock->socket_write("\n");
    sock->socket_read(buffer, 2000);
    cout << buffer << endl;
    return buffer;
}

void Network::sendToServer(shared_ptr<Socket> &sock,string &ts)
{
    sock->socket_write(ts);
}

void Network::closeConnection(shared_ptr<Socket> &sock)
{
    sock->close();
}