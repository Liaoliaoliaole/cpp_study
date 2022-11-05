
#include <cmath>
#include <sstream>
#include <bits/stdc++.h> 
#include "player.h"
#include "parse.h"

using namespace std;

Player::Player()
{
    this->id = " ";
    this->position.x=2100;
    this->position.y=1650;
}

Player::Player(string id)
{
    this->id = id;
    this->position.x=2100;
    this->position.y=1650;
}

Player::~Player(){}

Vectr Player::AMstadByPass(Vectr &b)
{
    Vectr goal(0,1650);
    Vectr standBy; 
    standBy.y= static_cast<int>(1.9*b.y-160*9);
    standBy.x= static_cast<int>(1.9*b.x-480*9);
    return standBy;
}

Vectr Player::AMstadByKick(Vectr &b)
{
    Vectr goal(4800,1650);
    Vectr standBy; 
    standBy.y= static_cast<int>(1.9*b.y-160*9);
    standBy.x= static_cast<int>(1.9*b.x-480*9);
    return standBy;
}

Vectr Player::readyToKick(Vectr &b)
{
    Vectr goal(4800,1650);
    Vectr target; 
    // double d_ballToDoor = sqrt(pow((goal.x-b.x),2) + pow((goal.y-b.y),2));
    // target.y= static_cast<int>(b.y-200*(b.y-goal.y)/d_ballToDoor);
    // target.x= static_cast<int>(b.x-200*(b.x-goal.x)/d_ballToDoor);
    // target.y= static_cast<int>(1.2*b.y-160*2);
    // target.x= static_cast<int>(1.2*b.x-480*2);
    // if((b.x < goal.x-400 && (b.y < goal.y+400 && b.y > goal.y-400))
    //     || ((b.x>400 && (b.y < goal.y+400 && b.y > goal.y-400)))){
    if(abs(b.x - goal.x) >=1)
    {
    double k= (b.y-goal.y)/(b.x-goal.x);
    target.x= (int)(-250/sqrt(k*k+1)+b.x);
    target.y = (int)(abs(250*k/sqrt(k*k+1)+b.y));
    }else
    {
        cout << "(!!!!!!!" << endl;
    }
    //}
    return target;  
}


string Player::sendCords(Vectr &v)
{
    string c = (this->id).substr(1) + "," + to_string(v.x) + "," + to_string(v.y) + "\n";
    cout << "*" << c << endl;
    return c;
}
