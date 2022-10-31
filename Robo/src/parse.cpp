#include <bits/stdc++.h> 
#include "parse.h"
using namespace std;

// void connectToServer(shared_ptr<Socket> sock){
// string ip = "localhost";
// string port = "10000";
// //auto sock = make_unique<Socket>(AF_INET,SOCK_STREAM,0);
// sock->connect(ip, port);
// }
string readFromServer(shared_ptr<Socket> sock)
{
    string buffer;
    sock->socket_read(buffer, 1024);
    cout << buffer << endl;
    cout << "***" << endl;
    return buffer;
}

void update(string &str,vector<shared_ptr<Object>> &o)
{
    stringstream ss(str);
    string line;
    while(getline(ss,line)){
        char key[2];
        float x,y;
        sscanf(line.c_str(),"%[B-R,1-5]: %f,%f",key,&x,&y);
        //cout << key << " " << x << " " << y << endl;
        string s = key;
        for(auto &ob: o){
            if(s==(ob->getID())){
                ob->position.x=(int)x;
                ob->position.y=(int)y;
            }
            // try
            // {
            //     if(ob->getID() != s){
            //     throw ob;
            //     }
            // }
            // catch(shared_ptr<Object> oo)
            // {
            //     cout<<oo->getID();
            // }
            // catch(const std::exception& e)
            // {
            //     std::cerr << e.what() << '\n';
            // }
        }

    }

}

vector<shared_ptr<Vectr>> circle_dance(int a, int b,int r){
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
    
