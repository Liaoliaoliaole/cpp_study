
#include <unistd.h>
#include "network.h"
#include "parser.h"
#include "strategy.h"

using namespace std;

int main(int argc,char*argv[]){
    auto sock = Network::connectToServer();
    auto os = Parser::initObjects();

    while(1)
    {
        sleep(0.02);
        //sleep(1);
        string buffer = Network::readFromServer(sock);
        Parser::parse(buffer,os);
        Strategy::AttackerL(os);
        Strategy::AttackerR(os);
        Strategy::Defender(os);
        Strategy::GoalKeeper(os);
        //Strategy::Midfielder(os);
        string positions = Parser::concatenate(os);
        Network::sendToServer(sock,positions);
    }    
    sock->close();
    return 0;
}
