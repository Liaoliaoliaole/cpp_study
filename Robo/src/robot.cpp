#include<iostream>
#include<memory>
#include<cmath>
#include<unistd.h>
#include"socket.h"
#include"point.h"

vector<shared_ptr<Point>> circle_dance(int a, int b,int r){
    if(a<r || b< r){
        cout << "invalid circle center." << endl;
        exit(-1);
    }else{
    vector<shared_ptr<Point>>circle;
        // circle.push_back(make_shared<Point>(a-r,b));
        // circle.push_back(make_shared<Point>(a,r+b));
        // circle.push_back(make_shared<Point>(r+a,b));
        // circle.push_back(make_shared<Point>(a,b-r));
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

int main(int argc,char*argv[]){
string ip = "192.168.0.106";
string port = "44440";
auto sock = make_unique<Socket>(AF_INET,SOCK_STREAM,0);
sock->connect(ip, port);
while(true){
for(auto &p : circle_dance(3000,2000,300)){
    sock->socket_write(p->display());
    usleep(50000);
}
}
   /*  vector<Socket> writes(1);
    writes[0] = *sock;
    int seconds = 5;
    if(sock->select(&writes, NULL, NULL, seconds) < 1){
     //Socket::select waits until sock reveives some input (for example the answer from google.com)
    
    //Something went wrong
 }else{
    string buffer;
    sock->socket_read(buffer, 1024);//Read 1024 bytes of the answer
    cout << buffer << endl;
} */



return 0;
}
