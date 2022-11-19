/*
 * Copyright (C) 2007 by Johan Dams, VAMK <jd@puv.fi>
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 */

#include <cmath>
#include "strategy.h"
#include "constants.h"

using namespace std;

void Strategy::AttackerL(vector<shared_ptr<Object>> &os)
{
    shared_ptr<Ball> b = dynamic_pointer_cast<Ball>(os.at(Constants::BALL));
    shared_ptr<Player> p = dynamic_pointer_cast<Player>(os.at(Constants::ATTACKEL));

    if(b->getFound()==true && b->isLeftFront()==true)
    {
    if(p->kickingArea(b)==true)
    {
        cout<<"in kicking triangle" <<endl;
        p->setTarget(b->position);
    }else if(p->kickingArea(b)==false && p->position.x <= b->position.x)
    {
        cout<<"moving to kicking point..."<<endl;
        Vector2 target(p->readyToKick(b));
        
        p->setTarget(target);
        p->limitTarget(Constants::FIELDX/3,Constants::FIELDY/2,Constants::FIELDX,Constants::FIELDY);
    }else if(p->kickingArea(b)==false && p->position.x > b->position.x && p->position.y >= b->position.y)
    {
        cout << "moving above the ball then go to kicking point" << endl;
        Vector2 top(b->position.x,b->position.y+Constants::KICKDISTANCE);
        p->setTarget(top);
    }else if(p->kickingArea(b)==false && p->position.x > b->position.x && p->position.y < b->position.y)
    {
        cout << "moving under the ball then go to kicking point" << endl;
        Vector2 bottom(b->position.x+Constants::KICKDISTANCE*2,b->position.y+10);
        p->setTarget(bottom);
    }
    }else
    {
        Vector2 AttakerStandby(Constants::FIELDX*3/4,Constants::FIELDY*3/4);
        p->setTarget(AttakerStandby);
    }
}

void Strategy::AttackerR(vector<shared_ptr<Object>> &os)
{
    shared_ptr<Ball> b = dynamic_pointer_cast<Ball>(os.at(Constants::BALL));
    shared_ptr<Player> p = dynamic_pointer_cast<Player>(os.at(Constants::ATTACKER));

    if(b->getFound()==true && b->isRightFront()==true)
    {
    if(p->kickingArea(b)==true)
    {
        cout<<"in kicking triangle" <<endl;
        p->setTarget(b->position);
    }else if(p->kickingArea(b)==false && p->position.x <= b->position.x)
    {
        cout<<"moving to kicking point..."<<endl;
        Vector2 target(p->readyToKick(b));
        
        p->setTarget(target);
        p->limitTarget(Constants::FIELDX/3,0,Constants::FIELDX,Constants::FIELDY/2);
    }else if(p->kickingArea(b)==false && p->position.x > b->position.x && p->position.y >= b->position.y)
    {
        cout << "moving above the ball then go to kicking point" << endl;
        Vector2 top(b->position.x-Constants::KICKDISTANCE,b->position.y+Constants::KICKDISTANCE);
        p->setTarget(top);
    }else if(p->kickingArea(b)==false && p->position.x > b->position.x && p->position.y < b->position.y)
    {
        cout << "moving under the ball then go to kicking point" << endl;
        Vector2 bottom(b->position.x,b->position.y-Constants::KICKDISTANCE);
        p->setTarget(bottom);
    }
    }else
    {
        Vector2 AttakerStandby(Constants::FIELDX*3/4,Constants::FIELDY*1/4);
        p->setTarget(AttakerStandby);
    }
}

//BASED ON ALINE ROBOT BALL AND CENTER OG GOAL
/* void Strategy::AttackerR(vector<shared_ptr<Object>> &os)
{
    shared_ptr<Ball> b = dynamic_pointer_cast<Ball>(os.at(Constants::BALL));
    shared_ptr<Player> p = dynamic_pointer_cast<Player>(os.at(Constants::ATTACKER));
    
    Vector2 target(p->readyToKick(b));
    p->limitTarget(Constants::FIELDX/3,0,Constants::FIELDX,Constants::FIELDY/2);

    if(b->found == true && b->isRightFront()==true)
    {
        if (b->position.x <= p->position.x)
        {
                cout << "Midfielder right of ball, ball down" << endl;
                Vector2 step_down(b->position.x,b->position.y-Constants::KICKDISTANCE);
                p->setTarget(step_down);

                if ((abs(p->position.x - step_down.x) <= Constants::OFFSET 
                        && abs(p->position.y - step_down.y) <= Constants::OFFSET))
                {
                    cout << "Midfielder at step down target" << endl;  
                    p->setTarget(target);
                }                 
                else if((abs(p->position.x - target.x) <= Constants::OFFSET)
                            && (abs(p->position.y - target.y) <= Constants::OFFSET))
                {
                    cout << "Midfielder at target" << endl;
                    p->setTarget(b->position);  
                }          
        }                          
        else if (b->position.x > p->position.x) 
        {
            if((abs(p->position.x - target.x) <= Constants::OFFSET)
                    && (abs(p->position.y - target.y) <= Constants::OFFSET))
            {
                cout << "r3=target" << endl;                     
                p->setTarget(b->position); 
            }else{
                cout << "Midfielder on the left" << endl;                      
                p->setTarget(target);
            }
        }
    }
} */

void Strategy::Defender(vector<shared_ptr<Object>> &os)
{
    shared_ptr<Ball> b = dynamic_pointer_cast<Ball>(os.at(Constants::BALL));
    shared_ptr<Player> pl = dynamic_pointer_cast<Player>(os.at(Constants::DEFENCELEFT));
    shared_ptr<Player> pr = dynamic_pointer_cast<Player>(os.at(Constants::DEFENCERIGHT));

    /*-------JD------*/
    Vector2 top;
    Vector2 bottom;
    Vector2 target(Constants::GOALX,Constants::GOALY/2);
    int pos_x = Constants::GOALWIDTH+100;
    top.x = pos_x;
    bottom.x = pos_x;
    /*standby position,x=500,y up and down:
    One align at ball and opponent's center point of goal to kick away, the othe align at ball and our own center point of goal to defence.*/
    top.y = (Constants::GOALY/2 + Constants::KICKDISTANCE) + (b->position.y - Constants::GOALY/2) * 0.5;
    bottom.y = (Constants::GOALY/2 - Constants::KICKDISTANCE) - (Constants::GOALY/2 - b->position.y) * 0.5;
    cout << "df station" << top.y << "and " << bottom.y <<endl;
    /*Take c as thr center of circle, 800 is the radius, move around the center of own door*/
    Vector2 c(0, Constants::GOALY/2);
    Vector2 v;
    double vX = top.x - c.x;
    double vY = top.y - c.y;
    double magV = sqrt(vX * vX + vY * vY);
    double aX = c.x + vX / magV * Constants::GOALWIDTH*2;
    double aY = c.y + vY / magV * Constants::GOALWIDTH*2;
    top.x = aX;
    top.y = aY;
    vX = bottom.x - c.x;
    vY = bottom.y - c.y;
    magV = sqrt(vX * vX + vY * vY);
    aX = c.x + vX / magV * 800;
    aY = c.y + vY / magV * 800;
    bottom.x = aX;
    bottom.y = aY;
    cout << "df station" << top.y << "and " << bottom.y <<endl;


    if (b->position.x < Constants::FIELDX/3) 
    {
        Vector2 target(pl->readyToKick(b));
        pl->setTarget(target);
        pr->setTarget(target);
        if(pl->kickingArea(b)==true)
        {
        pl->setTarget(b->position);
        }else if(pr->kickingArea(b)==true)
        {
        pr->setTarget(b->position);
        }
    }else
    {
        pl->setTarget(top);
        pr->setTarget(bottom);
    } 

}

void Strategy::GoalKeeper(vector<shared_ptr<Object>> &os)
{
    shared_ptr<Ball> b = dynamic_pointer_cast<Ball>(os.at(Constants::BALL));
    shared_ptr<Player> p = dynamic_pointer_cast<Player>(os.at(Constants::GOALKEEPER));
    Vector2 target;
    target.x = Constants::ROBOSIZE;
    //Align with ball and center of our own goal
    target.y = Constants::GOALY/2 + (b->position.y-Constants::GOALY/2)/2;
    p->setTarget(target);
    p->limitTarget(Constants::ROBOSIZE,Constants::GOALY/2-220,Constants::ROBOSIZE,Constants::GOALY/2+220);
    // if(target.y > Constants::GOALY/2 + 220){
	// 		target.y = Constants::GOALY/2 - 220;
	// 	}
	// 	else if(target.y < Constants::GOALY/2 - 220){
	// 		target.y = Constants::GOALY/2 + 220;
	// 	}
    //p->setTarget(target);
}
