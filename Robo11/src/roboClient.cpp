#include <unistd.h>
#include "constants.h"
#include "network.h"
#include "parser.h"
#include "strategy.h"
#include "kalmanFilter.h"

using namespace std;



int main(int argc,char*argv[]){
    auto sock = Network::connectToServer();
    auto os = Parser::initObjects();   

    while(1)
    {
        sleep(Constants::T);
        string buffer = Network::readFromServer(sock);
        Parser::parse(buffer,os);

        if(!(os.at(0)->kf).initializationStatus()){
            os.at(0)->initKalmanFilter();
        }
        os.at(0)->getNextPosition();

        Strategy::AttackerL(os);
        Strategy::AttackerR(os);
        Strategy::Defender(os);
        Strategy::GoalKeeper(os);
        string positions = Parser::concatenate(os);
        Network::sendToServer(sock,positions);
    }    
    sock->close();
    return 0;
}
