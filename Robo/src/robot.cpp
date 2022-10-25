#include<iostream>
#include<memory>
#include<cmath>
#include<sstream>  
#include<unistd.h>
#include"socket.h"
#include"point.h"

vector<shared_ptr<Point>> circle_dance(int a, int b,int r){
    if(a<r || b< r){
        cout << "invalid circle center." << endl;
        exit(-1);
    }else{
    vector<shared_ptr<Point>>circle;
        int x = a-r;
        int y = b;
        for(x=a-r;x<a+r;x=x+10){
            y=b+sqrt(r*r-pow(a-x,2));
            circle.push_back(make_shared<Point>(x,y));
        }
        for(x=a+r;x>a-r;x=x-10){
            y=b-sqrt(r*r-pow(a-x,2));
            circle.push_back(make_shared<Point>(x,y));
        }
     return circle;
    }
}

vector<string> split(string &s, char d){
    vector<string> output;
    stringstream ss(s);
    string sub;

    while(getline(ss,sub,d)){
        output.push_back(sub);
    }
    return output;
}

int main(int argc,char*argv[]){
string ip = "localhost";
string port = "10000";
auto sock = make_unique<Socket>(AF_INET,SOCK_STREAM,0);
sock->connect(ip, port);

string send_cords;
string send_cords_kick;
string buffer;
vector<string> read_cords;
auto maali_cords = make_shared<Point>(4750,1650);

while(1){
//read ball cordinates
sleep(0.2);
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





/*chase the ball and kick*/
//send_cords= to_string(x) + "," +to_string(y) + "\n";

}
sock->close();

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
return 0;
}
