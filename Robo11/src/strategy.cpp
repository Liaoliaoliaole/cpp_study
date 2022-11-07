#include <cmath>
#include "strategy.h"

#define ALLOW 300
#define RADIUS 350

using namespace std;

void Strategy::AttackingMidfield(shared_ptr<Socket> sock,shared_ptr<Ball> &b,shared_ptr<Player> &p)
{
    Vectr step_up(b->position.x,b->position.y+RADIUS);
    Vectr step_down(b->position.x,b->position.y-RADIUS);
    Vectr target(p->readyToKick(b->position));
    cout<< "target: " << target.x << "," << target.y <<endl;

    if(b->found == true && (b->position.x <3800 && b->position.x>1600))//ball between left midline and right midline
    {
        if((b->getPosition().x <= p->getPosition().x) && (b->position.y > 1650))//ball left of player and half up of field
        {
            cout << "AM right of ball,ball up" << endl;
            sock->socket_write(p->sendCords(step_up));
            if ((p->position.x - step_up.x)*(p->position.x - step_up.x) 
                        + (p->position.y - step_up.y)*(p->position.y - step_up.y) < ALLOW*ALLOW)//Atackmidfielder is at step up target area
            {
                cout << "AM at step up target" << endl; 
                int x=0,y=0;                
                for(x =b->position.x; x>target.x; x=x-20)
                {
                    y=(int)(b->position.y+sqrt(RADIUS*RADIUS-pow((x-b->position.x),2)));
                    Vectr tmp(x,y);
                    sock->socket_write(p->sendCords(tmp));
                }
                //sock->socket_write(p->sendCords(target));

                if((p->position.x - target.x)*(p->position.x - target.x) + (p->position.y - target.y)*(p->position.y - target.y) < ALLOW*ALLOW)//Attackmidfielder is at target area
                    {
                        cout << "AM target area" << endl;
                        sock->socket_write(p->sendCords(b->position)); 
                    }
            }
        }
        if ((b->getPosition().x <= p->getPosition().x) && (b->position.y <= 1650))//ball left of player and half down of field
        {
                cout << "AM rightof ball, ball down" << endl;
                sock->socket_write(p->sendCords(step_down)); 
                if ((p->position.x - step_down.x)*(p->position.x - step_down.x) 
                        + (p->position.y - step_down.y)*(p->position.y - step_down.y) < ALLOW*ALLOW)
                {
                    cout << "AM on step down target area" << endl;  
                    int x=0,y=0;                
                for(x =b->position.x; x>target.x; x=x-20)
                {
                    y=(int)(b->position.y+sqrt(RADIUS*RADIUS-pow((x-b->position.x),2)));
                    Vectr tmp(x,y);
                    sock->socket_write(p->sendCords(tmp));
                }
                    //sock->socket_write(p->sendCords(target));
                    }                 
                    if((p->position.x - target.x)*(p->position.x - target.x) 
                        + (p->position.y - target.y)*(p->position.y - target.y) < ALLOW*ALLOW)//player is at target position
                    {
                        cout << "AM target area" << endl;
                        sock->socket_write(p->sendCords(b->position)); 
                    }          
        }                          
        if (b->getPosition().x > p->getPosition().x)//attackmidfielder is at left of ball 
        {
            cout << "AM left" << endl;                      
            sock->socket_write(p->sendCords(target));
            if((p->position.x - target.x)*(p->position.x - target.x) 
                        + (p->position.y - target.y)*(p->position.y - target.y) < ALLOW*ALLOW)
            {
                cout << "AM target" << endl;                     
                sock->socket_write(p->sendCords(b->position)); 
            }
        }
    }else if(b->found == true && (b->position.x <= 1600))
    {
        Vectr V=p->AMstadByPass(b->position);
        sock->socket_write(p->sendCords(V));
    }else if(b->found == true && (b->position.x >= 3800))
    {
        Vectr V=p->AMstadByKick(b->position);
        sock->socket_write(p->sendCords(V));
    }
}

/* void Strategy::BackDefanceL(shared_ptr<Socket> sock,shared_ptr<Ball> &b,shared_ptr<Player> &p)
{
    Vectr step_up(b->position.x,b->position.y+300);
    Vectr normal_target(p->readyToKick(b->position));
    Vectr target(normal_target.x,normal_target.y+100);

    if(b->found == true && b->position.x <= 1600 && b->position.y >=1650) // ball is at our half side,up
    {
        if(b->getPosition().x <= p->getPosition().x)//player is at right side of ball 
        {
            cout << "Player right up" << endl;
            sock->socket_write(p->sendCords(step_up));//p goes up of the ball
            if ((abs(p->position.x - step_up.x) <= ALLOW 
                            && abs(p->position.y - step_up.y)<= ALLOW))//p is at step up target
            {
                cout << "Player at step up target" << endl;
                //arch path move to target
                int x=0,y=0;                
                for(x =b->position.x; x>target.x; x=x-20){
                    y=(int)(b->position.y+sqrt(300*300-pow((x-b->position.x),2)));
                    Vectr tmp(x,y);
                    sock->socket_write(p->sendCords(tmp));
                }                     
            }
        }
        if (b->getPosition().x > p->getPosition().x)//player is at left side of ball 
        {
            cout << "player left" << endl;                      
            sock->socket_write(p->sendCords(target)); 
            if((abs(p->position.x - target.x) <= TARGETALLOW)
                    && (abs(p->position.y - target.y) <= ALLOW))
            {
                cout << "player at target" << endl;                     
                sock->socket_write(p->sendCords(b->position)); 
            }
        }
    }else
    {
        
        Vectr L(500,2050);
        sock->socket_write(p->sendCords(L));
    }
}

void Strategy::BackDefanceR(shared_ptr<Socket> sock,shared_ptr<Ball> &b,shared_ptr<Player> &p)
{
    // Vectr step_down(b->position.x,b->position.y-300);
    // Vectr normal_target(p->readyToKick(b->position));
    // Vectr target(normal_target.x,normal_target.y-100);

    // if(b->found == true && b->position.x <= 1600 && b->position.y < 1650) // ball is at our half side
    // {
    //     if ((b->getPosition().x <= p->getPosition().x) && (b->position.y<=1650))//p is at right side
    //     {
    //             cout << "player right " << endl;
    //             sock->socket_write(p->sendCords(step_down)); 
    //             if ((abs(p->position.x - step_down.x) <= ALLOW 
    //                     && abs(p->position.y - step_down.y) <= ALLOW))//player at step down target
    //             {
    //                 cout << "player at step down target" << endl;                                          
    //                 //arch path move to target
    //                 int x=0,y=0;                   
    //                 for(x =b->position.x; x>target.x; --x){
    //                     y=(int)(b->position.y+sqrt(250*250-pow((x-b->position.x),2)));
    //                     Vectr tmp(x,y);
    //                     sock->socket_write(p->sendCords(tmp));
    //                 }              
    //                 if((abs(p->position.x - target.x) <= TARGETALLOW)
    //                         && (abs(p->position.y - target.y) <= ALLOW))//player is at target position
    //                 {
    //                     cout << "player at target" << endl;
    //                     sock->socket_write(p->sendCords(b->position)); 
    //                 }          
    //             }                          
    //     }
    //     if (b->getPosition().x > p->getPosition().x)//player is at left side of ball 
    //     {
    //         cout << "player left" << endl;                      
    //         sock->socket_write(p->sendCords(target)); 
    //         if((abs(p->position.x - target.x) <= TARGETALLOW)
    //                 && (abs(p->position.y - target.y) <= ALLOW))
    //         {
    //             cout << "r3=target" << endl;                     
    //             sock->socket_write(p->sendCords(b->position)); 
    //         }
    //     }
    // }else
    // {
        
    //     Vectr R(500,1450);
    //     sock->socket_write(p->sendCords(R));
    // }

    int centerline = 1650;
    int pos_x = 500;
    Vectr top;
    Vectr bottom;
    Vectr target(4800, 1650);
    top.x = pos_x;
    bottom.x = pos_x;
    top.y = (centerline + 200) + (b->position.y - 1650) * 0.5;
    bottom.y = (centerline - 200) - (1650 - b->position.y) * 0.5;
    Vectr c(0, 1650);
    double vX = top.x - c.x;
    double vY = top.y - c.y;
    double magV = sqrt(vX * vX + vY * vY);
    double aX = c.x + vX / magV * 800;
    double aY = c.y + vY / magV * 800;
    top.x = aX;
    top.y = aY;
    vX = bottom.x - c.x;
    vY = bottom.y - c.y;
    magV = sqrt(vX * vX + vY * vY);
    aX = c.x + vX / magV * 800;
    aY = c.y + vY / magV * 800;
    bottom.x = aX;
    bottom.y = aY;
    if ((b->position.x < 1200) {
    //   robots[this.defender_top].kick(target);
    //   robots[this.defender_bottom].kick(target);
    } else {
    //robots[this.defender_top].move(top, Boolean.valueOf(true), Boolean.valueOf(true), Boolean.valueOf(false));
    //   robots[this.defender_bottom].move(bottom, Boolean.valueOf(true), Boolean.valueOf(true), Boolean.valueOf(false));
    } 
}

void Strategy::GoalKeeper(shared_ptr<Socket> sock,shared_ptr<Ball> &b,shared_ptr<Player> &p)
{
    Vectr GoalKeepPosition;
    GoalKeepPosition.x = 120;
    GoalKeepPosition.y = 1650 + (b->position.y - 1650) * 0.5;
    if (GoalKeepPosition.y > 1870) {
      GoalKeepPosition.y = 1430;
    } else if (GoalKeepPosition.y < 1430) {
      GoalKeepPosition.y = 1870;
    }
    sock->socket_write(p->sendCords(GoalKeepPosition)); 
} */