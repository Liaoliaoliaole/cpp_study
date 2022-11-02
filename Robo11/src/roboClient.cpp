
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

while(1){
    sleep(0.5);
    string buffer = readFromServer(sock);
    update(buffer,os);
    Vectr r3Old = r3->position;
    cout << "r3Old" << r3Old.x << " " << r3Old.y << endl;
    toStepTarget(sock,os);
    // buffer = readFromServer(sock);
    // update(buffer,os);
    Vectr r3New = r3->position;
    cout << "r3new" << r3New.x << " " << r3New.y << endl;
    if((r3Old.x == r3New.x) && (r3Old.y == r3New.y)){
        cout << "*" << endl;
        while(1){
            sleep(0.5);
            buffer = readFromServer(sock);
            update(buffer,os);
            Vectr r3Old_t = r3->position;
            cout << "r3Old_t" << r3Old_t.x << " " << r3Old_t.y << endl;
            ToTarget(sock,os);
            // buffer = readFromServer(sock);
            // update(buffer,os);
            Vectr r3New_t = r3->position;
            cout << "r3new_t" << r3New_t.x << " " << r3New_t.y << endl;
            if ((r3Old_t.x == r3New_t.x) && (r3Old_t.y == r3New_t.y))
            {
                cout << "**" << endl;
                while(1){
                    sleep(0.5);
                    buffer = readFromServer(sock);
                    update(buffer,os);
                    Vectr r3Old_k = r3->position;
                    sock->socket_write(ball->getPosition().printToCords());
                    r3->setPosition(ball->getPosition());
                    // buffer = readFromServer(sock);
                    // update(buffer,os);
                    Vectr r3New_k = r3->position;
                    if ((r3Old_k.x == r3New_k.x) && (r3Old_k.y == r3New_k.y))
                    {
                        cout << "***" << endl;
                        break;
                    }
                }
                break;
            }
            cout << "not yet arrive target" << endl;
    // for(auto &o:os){
    //     cout<< "changed" << o->getID() << " " << o->getPosition().printToCords();
    // }
        }
    }
    cout << "not yet to step" << endl;
}    

/*
string send_cords;
string send_cords_kick;
string buffer;
vector<string> read_cords;
auto maali_cords = make_shared<Point>(4750,1650);

while(1){
//read ball cordinates
sleep(0.02);
sock->socket_read(buffer, 1024);//Read 1024 bytes
cout << buffer << endl;
//parse the buffer
read_cords = split(buffer,',');
cout << read_cords.at(0) <<endl;
cout << read_cords.at(1) <<endl;
//get integers from buffer
int x = stoi(read_cords.at(0));
int y = stoi(read_cords.at(1));
auto ball_cords = make_shared<Point>(x,y);
// calculate robot ready to kick position
Point ready_kick(maali_cords, ball_cords);
cout << ready_kick.get_x() << endl;
cout << ready_kick.get_y() << endl;

send_cords = ready_kick.display();
sock->socket_write(send_cords);
sleep(0.1);
send_cords_kick = ball_cords->display();
sock->socket_write(send_cords_kick);
*/




/*chase the ball and kick*/
//send_cords= to_string(x) + "," +to_string(y) + "\n";

//}



//openning show: circle dance

sock->close();
return 0;
}
