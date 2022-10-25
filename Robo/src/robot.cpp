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
string buffer;
vector<string> cords;

while(1){
sock->socket_write(send_cords);
sock->socket_read(buffer, 1024);//Read 1024 bytes
cout << buffer << endl;
cords = split(buffer,',');
cout << cords.at(0) <<endl;
cout << cords.at(1) <<endl;

int x = stoi(cords.at(0));
int y = stoi(cords.at(1));

send_cords= to_string(x) + "," +to_string(y) + "\n";
//sleep(0.2);
}
sock->close();
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
