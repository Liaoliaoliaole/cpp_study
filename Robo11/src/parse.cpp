#include <bits/stdc++.h> 
#include <memory>
#include "parse.h"
#include "player.h"
#include "ball.h"

#define ALLOW 1
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
    return buffer;
}

void parseAndSetCords(string &str,vector<shared_ptr<Object>> &o)
{
    stringstream ss(str);
    string line;
    while(getline(ss,line)){
        char key[20];
        float x,y;
        sscanf(line.c_str(),"%[B-R,1-5]: %f,%f",key,&x,&y);
        //cout << key << " " << x << " " << y << endl;
        string s = key;
        for(auto &ob: o){
            if(s==(ob->getID())){
                ob->position.x=(int)(x+0.5);
                ob->position.y=(int)(y+0.5);
            }
        }

    }

}

/* void toStepTarget(shared_ptr<Socket> sock,vector<shared_ptr<Object>> &os)
{
    shared_ptr<Ball> b = dynamic_pointer_cast<Ball>(os.at(0));
    shared_ptr<Player> p3 = dynamic_pointer_cast<Player>(os.at(3));   
    cout << "---" << endl;
    Vectr step_up(b->position.x,b->position.y+200);
    Vectr step_down(b->position.x,b->position.y-200);
    if(b->position.x <= p3->position.x && b->position.y <= p3->position.y)//r3 is at right up of ball
    {
        cout << "r3 right up" << endl;
        sock->socket_write(step_up.printToCords());
        p3->setPosition(step_up);
    }
    if (b->getPosition().x <= p3->getPosition().x && b->getPosition().y > p3->getPosition().y)//r3 is at right down of ball
    {
        cout << "r3 right down" << endl;
        sock->socket_write(step_down.printToCords());   
        p3->setPosition(step_down);                         
    }
        
}

void ToTarget(shared_ptr<Socket> sock,vector<shared_ptr<Object>> &os)
{
    shared_ptr<Ball> b = dynamic_pointer_cast<Ball>(os.at(0));
    shared_ptr<Player> p3 = dynamic_pointer_cast<Player>(os.at(3));   

    Vectr target(p3->readyToKick(b->position));
    cout<< "target: " << target.x << "," << target.y <<endl;

    if (b->getPosition().x > p3->getPosition().x)//r3 is at left side of ball 
    {
        cout << "r3 left" << endl;                      
        sock->socket_write(target.printToCords());
        p3->setPosition(target);
    } 
} */

 void planToTarget(shared_ptr<Socket> sock,vector<shared_ptr<Object>> &os)
{
    shared_ptr<Ball> b = dynamic_pointer_cast<Ball>(os.at(0));
    shared_ptr<Player> p3 = dynamic_pointer_cast<Player>(os.at(3));  
    Vectr step_up(b->position.x,b->position.y+150);
    Vectr step_down(b->position.x,b->position.y-150);
    Vectr target(p3->readyToKick(b->position));
    cout<< "target: " << target.x << "," << target.y <<endl;

    if(b->found == true && b->position.x >1200)
    {
        if(b->getPosition().x <= p3->getPosition().x && b->getPosition().y <= p3->getPosition().y)//r3 is at right up of ball
        {
            cout << "r3 right up" << endl;
            sock->socket_write(step_up.printToCords());
            if ((abs(p3->position.x - step_down.x) <= ALLOW 
                    && abs(p3->position.y - step_down.y) <= ALLOW)
                        ||(abs(p3->position.x - step_up.x) <= ALLOW 
                            && abs(p3->position.y - step_up.y)<= ALLOW))//r3 = any step target
            {
                cout << "r3=any step target" << endl;                       
                sock->socket_write(target.printToCords());
                        //p3->setPosition(target);
            }
        }
        if (b->getPosition().x <= p3->getPosition().x && b->getPosition().y > p3->getPosition().y)//r3 is at right down of ball
        {
                cout << "r3 right down" << endl;
                sock->socket_write(step_down.printToCords()); 
                if ((abs(p3->position.x - step_down.x) <= ALLOW 
                        && abs(p3->position.y - step_down.y) <= ALLOW)
                            ||(abs(p3->position.x - step_up.x) <= ALLOW 
                                && abs(p3->position.y - step_up.y)<= ALLOW))//r3 = any step target
                {
                    cout << "r3=any step target" << endl;                       
                    sock->socket_write(target.printToCords()); 
                    if(p3->position.x == target.x && p3->position.y == target.y/* abs(p3->position.x - target.x) <= ALLOW)
                            && (abs(p3->position.y - target.y) <= ALLOW) */)//r3 is at target position
                    {
                        cout << "r3=target" << endl;

                        sock->socket_write(b->position.printToCords());
                    //p3->setPosition(b->position);
                    }          
                }                          
        }
        if (b->getPosition().x > p3->getPosition().x)//r3 is at left side of ball 
        {
            cout << "r3 left" << endl;                      
            sock->socket_write(target.printToCords());
            if(p3->position.x == target.x && p3->position.y == target.y/* (abs(p3->position.x - target.x) <= ALLOW)
                    && (abs(p3->position.y - target.y) <= ALLOW) */)//r3 is at target position
            {
                cout << "r3=target" << endl;                       
                sock->socket_write(b->position.printToCords());
                    //p3->setPosition(b->position);
            }
        }
        if(p3->position.x == target.x && p3->position.y == target.y/* abs(p3->position.x - target.x) <= ALLOW)
                            && (abs(p3->position.y - target.y) <= ALLOW) */)//r3 is at target position
                    {
                        cout << "r3=target" << endl;

                        sock->socket_write(b->position.printToCords());
                    //p3->setPosition(b->position);
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
    
