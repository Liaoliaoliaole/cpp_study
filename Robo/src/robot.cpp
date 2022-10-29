#include <iostream>
#include <memory>
#include <cmath>
#include <unistd.h>
#include <sstream>  
#include <iterator>
#include <vector>
#include <map>
#include "socket.h"
#include "vectr.h"
#include "parse.h"

/*
vector<string> split(string &s, char d){
    vector<string> output;
    stringstream ss(s);
    string sub;

    while(getline(ss,sub,d)){
        output.push_back(sub);
    }
    return output;
}
*/


int main(int argc,char*argv[]){
string ip = "localhost";
string port = "10000";
auto sock = make_unique<Socket>(AF_INET,SOCK_STREAM,0);
sock->connect(ip, port);

string buffer;

while(1){
    sleep(0.02);
    sock->socket_read(buffer, 1024);
    cout << buffer << endl;
    cout << endl;
    //parse the buffer save cords in map type.
    auto cords_map = split(buffer);
    for(auto it = cords_map.cbegin(); it != cords_map.cend(); ++it){
    std::cout << it->first << " " << (it->second).x << "," << (it->second).y << "\n";
    }
    sock->socket_write(cords_map["B"].printToCords());
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
/*
while(true){
for(auto &p : circle_dance(3000,2000,300)){
    sock->socket_write(p->display());
    usleep(20000);
}
}
*/


   /*  vector<Socket> reads(1);
    reads[0] = *sock;
    int seconds = 5;
    if(sock->select(&reads, NULL, NULL, seconds) < 1){
     //Socket::select waits until sock reveives some input (for example the answer from google.com)
    
    //Something went wrong
 }else{
    string buffer;
    sock->socket_read(buffer, 1024);//Read 1024 bytes of the answer
    cout << buffer << endl;
} */
//sock->close();
return 0;
}
