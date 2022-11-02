
#include <cmath>
#include "player.h"

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

Vectr Player::readyToKick(Vectr &b)
{
    Vectr goal(4800,1650);
    Vectr target; 
   // double d_ballToDoor = sqrt(pow((goal.x-b.x),2) + pow((goal.y-b.y),2));
    // double k = (goal.y-b.y)/(goal.x-b.x);
    // target.y= static_cast<int>(abs(b.y-(k*250/sqrt(k*k+1))));
    // target.x= static_cast<int>(abs(b.x-250/sqrt(k*k+1)));
    // target.x= static_cast<int>((200/sqrt(pow((goal.y-b.y)/(goal.x-b.x),2)+1))+b.x);
    // target.y = static_cast<int>(((goal.y-b.y)/(goal.x-b.x))*(target.x-b.x)+b.y);
    // target.y= static_cast<int>(b.y-300*(b.y-goal.y)/d_ballToDoor);
    // target.x= static_cast<int>(b.x-300*(b.x-goal.x)/d_ballToDoor);
    target.y= static_cast<int>(1.2*b.y-160*2);
    target.x= static_cast<int>(1.2*b.x-480*2);
    return target;  
}

// void Player::move(map<string,Vectr> cords, Vectr &b, shared_ptr<Socket> &sock)
// {
//     Vectr maali(4800,1650);
//     Vectr target; 
//     double d_ballToDoor = sqrt(pow((maali.x-b.x),2) + pow((maali.y-b.y),2));
//     target.y = (int)(b.y - 300*abs(maali.y-b.y)/d_ballToDoor);
//     target.x = (int)(b.x - 300*abs(maali.x-b.x)/d_ballToDoor); 
//     //target.x = (maali.y-b.y)/(maali.x-b.x);
//     //target.y = b.y-target.x*b.x;
//     Vectr l_target = this->limitRange(target);
//     Vectr step_target_up(b.x,(b.y+100));
//     Vectr l_step_target_up = this->limitRange(step_target_up);
//     Vectr step_target_down(b.x,(b.y-100));
//     Vectr l_step_target_down = this->limitRange(step_target_down);
//     if(b.x > this->getPosx()){
//         //this->setPosition(l_target);
//         sock->socket_write(l_target.printToCords());
//         //sock->socket_write(b->position.printToCords());
//     }else if (b.x <= this->getPosx() && b.y < this->getPosy()){
//         //this->setPosition(step_target_up);
//         sock->socket_write(l_step_target_up.printToCords());
//         sock->socket_write(l_target.printToCords());
//         //sock->socket_write(b->position.printToCords());
//     }else if(b.x <= this->getPosx() && b.y > this->getPosy()){
//         //this->setPosition(step_target_down);
//         sock->socket_write(l_step_target_down.printToCords());
//         sock->socket_write(l_target.printToCords());
//         //sock->socket_write(b->position.printToCords());
//     }
// }
