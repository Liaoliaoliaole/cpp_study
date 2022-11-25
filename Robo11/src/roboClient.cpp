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

    KalmanFilter kf;
    int Sx = 0, Sy = 0;

    while(1)
    {
        sleep(Constants::T);
        string buffer = Network::readFromServer(sock);
        Parser::parse(buffer,os);

        Sx = os.at(0)->position.x;
        Sy = os.at(0)->position.y; 

        if(!kf.isInitialized())
        {
            Eigen::VectorXd x_in(4, 1);
            x_in << Sx, Sy, 0.0, 0.0;
            kf.initialization(x_in);
            kf.SetP();
            kf.SetQ();
            kf.SetH();
            kf.SetR(); 
            kf.SetF();   
            continue;
        }
         // predict state vector x and state covariance matrix P
        kf.prediction();
         // update state vector x and state covariance matrix P
        Eigen::VectorXd z(2,1);
        z << Sx, Sy;
        kf.measurementUpdate(z);
        Eigen::VectorXd x_out(4,1);
        x_out = kf.GetX();
        cout << "Kalman filter output Sx is: " << x_out(0)
                    << ", output Sy is: " << x_out(1) << std::endl;


        Strategy::AttackerL(os);
        //Strategy::AttackerR(os);
        //Strategy::Defender(os);
        //Strategy::GoalKeeper(os);
        //Strategy::Midfielder(os);
        string positions = Parser::concatenate(os);
        Network::sendToServer(sock,positions);
    }    
    sock->close();
    return 0;
}
