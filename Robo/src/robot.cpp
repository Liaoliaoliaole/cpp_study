#include<iostream>
#include<memory>
#include"socket.h"
#include"point.h"

vector<shared_ptr<Point>> circle_dance(int a, int b,int r){
    auto c = make_shared<Point>(a,b);//center of circle
    int d=1.25-r;
    int x=0;
    int y=r;
    vector<shared_ptr<Point>>circle;
    for(; x<y;++x){
        circle.push_back(make_shared<Point>(a,y+b));
        circle.push_back(make_shared<Point>(x+a,y+b));
        circle.push_back(make_shared<Point>(y+a,x+b));
        circle.push_back(make_shared<Point>(x+a,b));
        circle.push_back(make_shared<Point>(y+a,-x+b));
        circle.push_back(make_shared<Point>(x+a,-y+b));
        circle.push_back(make_shared<Point>(a,-y+b));
        circle.push_back(make_shared<Point>(-x+a,-y+b));
        circle.push_back(make_shared<Point>(-y+a,-x+b));
        circle.push_back(make_shared<Point>(-x+a,b));
        circle.push_back(make_shared<Point>(-y+a,x+b));
        circle.push_back(make_shared<Point>(-x+a,y+b));
        if(d<=0){
            d+=2*x+3;
        }else{
            y--;
            d+=2*(x-y)+5;
        }
    }
     return circle;
}

int main(int argc,char*argv[]){

// string ip = Socket::ipFromHostName("google.com"); //Get ip addres from hostname
// string port = "80"; //let's talk on http port
// //Socket *sock = new Socket(AF_INET,SOCK_STREAM,0);  //AF_INET (Internet mode) SOCK_STREAM (TCP mode) 0 (Protocol any)
// auto sock = make_unique<Socket>(AF_INET,SOCK_STREAM,0);
// sock->connect(ip, port); //Connect to google.com:80
// sock->socket_write("GET / HTTP/1.1\r\n\r\n");//Send GET request to google.com:80
// int seconds = 10;//Wait 10 second for response
// vector<Socket> reads(1);
// reads[0] = *sock;

string ip = "192.168.0.106";
string port = "44440";
auto sock = make_unique<Socket>(AF_INET,SOCK_STREAM,0);
sock->connect(ip, port);

for(auto &p : circle_dance(3000,2000,300)){
    sock->socket_write(p->display());
    sleep(1);
}
    vector<Socket> writes(1);
    writes[0] = *sock;
    int seconds = 3;
    if(sock->select(&writes, NULL, NULL, seconds) < 1){
     //Socket::select waits until sock reveives some input (for example the answer from google.com)
    
    //Something went wrong
 }else{
    string buffer;
    sock->socket_read(buffer, 1024);//Read 1024 bytes of the answer
    cout << buffer << endl;






    
    


// int seconds = 5;
// vector<Socket> reads(1);
// reads[0] = *sock;
// if(sock->select(&reads, NULL, NULL, seconds) < 1){
//     //Socket::select waits until sock reveives some input (for example the answer from google.com)
    
//     //Something went wrong
// }else{
//     string buffer;
//     sock->socket_read(buffer, 1024);//Read 1024 bytes of the answer
//     cout << buffer << endl;
// }
    
}


return 0;
}
