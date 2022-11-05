#include <bits/stdc++.h> 
#include <memory>
#include "parse.h"

using namespace std;

void Parse::connectToServer(shared_ptr<Socket> sock)
{
string ip = "localhost";
string port = "10000";
//auto sock = make_unique<Socket>(AF_INET,SOCK_STREAM,0);
sock->connect(ip, port);
}

string Parse::readFromServer(shared_ptr<Socket> sock)
{
    string buffer;
    sock->socket_write("\n");
    sock->socket_read(buffer, 1024);
    cout << buffer << endl;
    return buffer;
}

void Parse::parseAndSetCords(string &str,vector<shared_ptr<Object>> &o)
{
    stringstream ss(str);
    string line;
    while(getline(ss,line)){
        char key[20];
        float x,y;
        sscanf(line.c_str(),"%[B-R,1-5]: %f,%f",key,&x,&y);
        string s = key;
        for(auto &ob: o){
            if(s==(ob->getID())){
                ob->position.x=(int)(x+0.5);
                ob->position.y=(int)(y+0.5);
            }
        }

    }

}

vector<shared_ptr<Vectr>> Parse::circle_dance(int a, int b,int r){
    if(a<r || b< r){
        cout << "invalid circle center." << endl;
        exit(-1);
    }else{
    vector<shared_ptr<Vectr>>circle;
        int x = a-r;
        int y = b;
        for(x=a-r;x<a+r;x=x+10){
            y=b+sqrt(r*r-pow(a-x,2));
            circle.push_back(make_shared<Vectr>(x,y));
        }
        for(x=a+r;x>a-r;x=x-10){
            y=b-sqrt(r*r-pow(a-x,2));
            circle.push_back(make_shared<Vectr>(x,y));
        }
     return circle;
    }
}


    
