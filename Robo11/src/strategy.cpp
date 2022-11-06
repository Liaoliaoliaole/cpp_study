#include <cmath>
#include "strategy.h"

#define ALLOW 100
#define TARGETALLOW 250

using namespace std;

void Strategy::AttackingMidfield(shared_ptr<Socket> sock,shared_ptr<Ball> &b,shared_ptr<Player> &p)
{
    Vectr step_up(b->position.x,b->position.y+250);
    Vectr step_down(b->position.x,b->position.y-250);
    Vectr target(p->readyToKick(b->position));
    cout<< "target: " << target.x << "," << target.y <<endl;

    if(b->found == true && (b->position.x <3800 && b->position.x>1600))/*  && (b->position.y <2050 && b->position.y >1250) *///ball is not already in opponent's door
    {

        if((b->getPosition().x <= p->getPosition().x) && (b->position.y > 1650))//ball left of player and half up of field
        {
            cout << "r3 right of ball,ball up" << endl;
            sock->socket_write(p->sendCords(step_up));
            if ((abs(p->position.x - step_up.x) <= ALLOW 
                            && abs(p->position.y - step_up.y)<= ALLOW))//r3 = step up target
            {
                cout << "r3 step up target" << endl; 
                sock->socket_write(p->sendCords(target));

                if((abs(p->position.x - target.x) <= TARGETALLOW)
                            && (abs(p->position.y - target.y) <= ALLOW))//r3 is at target position
                    {
                        cout << "r3=target" << endl;
                        sock->socket_write(p->sendCords(b->position)); 
                    }
            }
        }
        if ((b->getPosition().x <= p->getPosition().x) && (b->position.y <= 1650))//ball left of player and half down of field
        {
                cout << "r3 rightof ball, ball down" << endl;
                sock->socket_write(p->sendCords(step_down)); 
                if ((abs(p->position.x - step_down.x) <= ALLOW 
                        && abs(p->position.y - step_down.y) <= ALLOW))
                {
                    cout << "r3 step down target" << endl;  
                    sock->socket_write(p->sendCords(target));
                    }                 
                    if((abs(p->position.x - target.x) <= TARGETALLOW)
                            && (abs(p->position.y - target.y) <= ALLOW))//r3 is at target position
                    {
                        cout << "r3=target" << endl;
                        sock->socket_write(p->sendCords(b->position)); 
                    }          
        }                          
        if (b->getPosition().x > p->getPosition().x)//r3 is at left side of ball 
        {
            cout << "r3 left" << endl;                      
            sock->socket_write(p->sendCords(target));
            if((abs(p->position.x - target.x) <= TARGETALLOW)
                    && (abs(p->position.y - target.y) <= ALLOW))
            {
                cout << "r3=target" << endl;                     
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

void Strategy::BackDefanceL(shared_ptr<Socket> sock,shared_ptr<Ball> &b,shared_ptr<Player> &p)
{
    Vectr step_up(b->position.x,b->position.y+300);
    Vectr step_down(b->position.x,b->position.y-300);
    Vectr target(p->readyToKick(b->position));

    if(b->found == true && b->position.x <= 1600 && b->position.y >=1650) // ball is at our half side,up
    {
        

        if((b->getPosition().x <= p->getPosition().x /* && b->getPosition().y <= p->getPosition().y */&& (b->position.y > 1650)))//p is at right side of ball and ball is at up half
        {
            cout << "Player right up" << endl;
            sock->socket_write(p->sendCords(step_up));//p goes up of the ball
            if ((abs(p->position.x - step_up.x) <= ALLOW 
                            && abs(p->position.y - step_up.y)<= ALLOW))//p is at step up target
            {
                cout << "Player at step up target" << endl;

                int x=0,y=0; 
                Vectr tmp(x,y);
                for(x =b->position.x; x>target.x; --x){
                    y=(int)(b->position.y+sqrt(250*250-pow((x-b->position.x),2)));
                    sock->socket_write(p->sendCords(tmp));
                }                    
                //sock->socket_write(p->sendCords(target));    
            }
        }
        if ((b->getPosition().x <= p->getPosition().x/*  && b->getPosition().y > p->getPosition().y */) && (b->position.y<=1650))//p is at right side ball and ball is at down half
        {
                cout << "r3 right down" << endl;
                sock->socket_write(p->sendCords(step_down)); 
                if ((abs(p->position.x - step_down.x) <= ALLOW 
                        && abs(p->position.y - step_down.y) <= ALLOW))//player at step down target
                {
                    cout << "r3=any step target" << endl;                                          
                    
                    int x=0,y=0; 
                    Vectr tmp(x,y);
                    for(x =b->position.x; x>target.x; --x){
                        y=(int)(b->position.y+sqrt(250*250-pow((x-b->position.x),2)));
                        sock->socket_write(p->sendCords(tmp));
                    }              
                    if((abs(p->position.x - target.x) <= TARGETALLOW)
                            && (abs(p->position.y - target.y) <= ALLOW))//r3 is at target position
                    {
                        cout << "r3=target" << endl;
                        sock->socket_write(p->sendCords(b->position)); 
                    }          
                }                          
        }
        if (b->getPosition().x > p->getPosition().x)//r3 is at left side of ball 
        {
            cout << "r3 left" << endl;                      
            sock->socket_write(p->sendCords(target)); 
            if((abs(p->position.x - target.x) <= TARGETALLOW)
                    && (abs(p->position.y - target.y) <= ALLOW))
            {
                cout << "r3=target" << endl;                     
                sock->socket_write(p->sendCords(b->position)); 
            }
        }
    }else
    {
        
        Vectr L(380,1850);
        sock->socket_write(p->sendCords(L));
    }
}

void Strategy::BackDefanceR(shared_ptr<Socket> sock,shared_ptr<Ball> &b,shared_ptr<Player> &p)
{
    Vectr step_up(b->position.x,b->position.y+300);
    Vectr step_down(b->position.x,b->position.y-300);
    Vectr target(p->readyToKick(b->position));

    if(b->found == true && b->position.x <= 1600 && b->position.y < 1650) // ball is at our half side
    {
        

        if((b->getPosition().x <= p->getPosition().x /* && b->getPosition().y <= p->getPosition().y */&& (b->position.y > 1650)))//p is at right side of ball and ball is at up half
        {
            cout << "Player right up" << endl;
            sock->socket_write(p->sendCords(step_up));//p goes up of the ball
            if ((abs(p->position.x - step_up.x) <= ALLOW 
                            && abs(p->position.y - step_up.y)<= ALLOW))//p is at step up target
            {
                cout << "Player at step up target" << endl;

                int x=0,y=0; 
                
                for(x =b->position.x; x>target.x; --x){
                    y=(int)(b->position.y+sqrt(250*250-pow((x-b->position.x),2)));
                    Vectr tmp(x,y);
                    sock->socket_write(p->sendCords(tmp));
                }                    
                //sock->socket_write(p->sendCords(target));    
            }
        }
        if ((b->getPosition().x <= p->getPosition().x/*  && b->getPosition().y > p->getPosition().y */) && (b->position.y<=1650))//p is at right side ball and ball is at down half
        {
                cout << "r3 right down" << endl;
                sock->socket_write(p->sendCords(step_down)); 
                if ((abs(p->position.x - step_down.x) <= ALLOW 
                        && abs(p->position.y - step_down.y) <= ALLOW))//player at step down target
                {
                    cout << "r3=any step target" << endl;                                          
                    
                    int x=0,y=0; 
                    
                    for(x =b->position.x; x>target.x; --x){
                        y=(int)(b->position.y+sqrt(250*250-pow((x-b->position.x),2)));
                        Vectr tmp(x,y);
                        sock->socket_write(p->sendCords(tmp));
                    }              
                    if((abs(p->position.x - target.x) <= TARGETALLOW)
                            && (abs(p->position.y - target.y) <= ALLOW))//r3 is at target position
                    {
                        cout << "r3=target" << endl;
                        sock->socket_write(p->sendCords(b->position)); 
                    }          
                }                          
        }
        if (b->getPosition().x > p->getPosition().x)//r3 is at left side of ball 
        {
            cout << "r3 left" << endl;                      
            sock->socket_write(p->sendCords(target)); 
            if((abs(p->position.x - target.x) <= TARGETALLOW)
                    && (abs(p->position.y - target.y) <= ALLOW))
            {
                cout << "r3=target" << endl;                     
                sock->socket_write(p->sendCords(b->position)); 
            }
        }
    }else
    {
        
        Vectr L(380,1450);
        sock->socket_write(p->sendCords(L));
    }
}