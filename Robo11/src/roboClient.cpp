
#include <unistd.h>
#include "parse.h"
#include "ball.h"
#include "player.h"
#include "opponent.h"

using namespace std;

int main(int argc,char*argv[]){
    //connect to RoboServer
    string ip = "localhost";
    string port = "10000";
    auto sock = make_shared<Socket>(AF_INET,SOCK_STREAM,0);
    sock->connect(ip, port);
    
    //create all players and a ball
    auto ball = make_shared<Ball>();
    auto r1 = make_shared<Player>("R1");
    auto r2 = make_shared<Player>("R2");
    auto r3 = make_shared<Player>("R3");
    auto r4 = make_shared<Player>("R4");
    auto r5 = make_shared<Player>("R5");
    auto o1 = make_shared<Opponent>("O1");
    auto o2 = make_shared<Opponent>("O2");
    auto o3 = make_shared<Opponent>("O3");
    auto o4 = make_shared<Opponent>("O4");
    auto o5 = make_shared<Opponent>("O5");

    vector<shared_ptr<Object>> os;
    os.push_back(ball);
    os.push_back(r1);
    os.push_back(r2);
    os.push_back(r3);
    os.push_back(r4);
    os.push_back(r5);
    os.push_back(o1);
    os.push_back(o2);
    os.push_back(o3);
    os.push_back(o4);
    os.push_back(o5);

    string buffer;

while(1){
    sleep(0.02);
    //sleep(1);
    sock->socket_write("\n");
    buffer = readFromServer(sock);
    parseAndSetCords(buffer,os);
   
    planToTarget(sock,os);
    
    //openning show: circle dance()
}    
sock->close();
return 0;
}
