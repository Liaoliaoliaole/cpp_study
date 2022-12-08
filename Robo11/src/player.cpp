
#include <cmath>
#include <sstream>
#include <bits/stdc++.h> 
#include "player.h"
#include "parser.h"
#include "constants.h"

using namespace std;

Player::Player()
{
    this->id = " ";
    this->position.x=Constants::NORMALIZEX;
    this->position.y=Constants::NORMALIZEY;
    this->target.x=Constants::NORMALIZEX;
    this->target.y=Constants::NORMALIZEY;
}

Player::Player(string id)
{
    this->id = id;
    this->position.x=Constants::NORMALIZEX;
    this->position.y=Constants::NORMALIZEY;
    this->target.x=Constants::NORMALIZEX;
    this->target.y=Constants::NORMALIZEY;
}

Player::~Player(){}

objectTypes Player::getType()
{
    return objectTypes::Player;
}

void Player::setTarget(Vector2 &t)
{
    this->target.x = t.x;
    this->target.y = t.y;
}

Vector2 Player::getTarget()
{
    return this->target;
}

void Player::limitTarget(int min_x, int min_y,int max_x, int max_y)
{
    if (this->target.x < min_x)
    {
        this->target.x = min_x;
    }else if (this->target.x > max_x)
    {
        this->target.x = max_x;
    }
    
    if (this->target.y < min_y)
    {
        this->target.y = min_y;
    }else if (this->target.y > max_y)
    {
        this->target.y = max_y;
    }
}

bool Player::kickingArea(shared_ptr<Ball> &b)
{
    Vector2 up(Constants::GOALX,Constants::GOALUPY);
    Vector2 down(Constants::GOALX,Constants::GOALDOWNY);
    Vector2 p_up,p_down;
    
    if(b->isLeftFront()==true && b->isInGoal()==false && Constants::GOALX != b->getPosition().x)
    {
    p_up.x = b->getPosition().x-Constants::KICKAREA;
    p_down.x = p_up.x;
    p_up.y = b->getPosition().y+Constants::KICKAREA*(b->getPosition().y-Constants::GOALDOWNY)/(Constants::GOALX-b->getPosition().x);
    p_down.y = p_up.y-(Constants::GOALUPY-Constants::GOALDOWNY)*Constants::KICKAREA/(Constants::GOALX-b->getPosition().x);
    // cout <<"--------------------ball point "<< b->getPosition().x << "," << b->getPosition().y <<endl;
    // cout <<"--------------------up point "<< p_up.x << "," << p_up.y <<endl;
    // cout <<"--------------------down point "<< p_down.x << "," << p_down.y <<endl;
        if (this->position.isInTriangle(b->getPosition(),p_down,p_up,this->position)==true)
        {
            return true;
        }else{
            return false;
        }
    }else if(b->isRightFront()==true && b->isInGoal()==false && down.x != b->getPosition().x)
    {
    p_up.x = b->getPosition().x-Constants::KICKAREA;
    p_down.x = p_up.x;   
    p_down.y = b->getPosition().y-Constants::KICKAREA*(Constants::GOALUPY-b->getPosition().y)/(Constants::GOALX-b->getPosition().x);
    p_up.y = b->getPosition().y-Constants::KICKAREA*(Constants::GOALDOWNY-b->getPosition().y)/(Constants::GOALX-b->getPosition().x);
    // cout <<"--------------------ball point "<< b->getPosition().x << "," << b->getPosition().y <<endl;
    // cout <<"--------------------up point "<< p_up.x << "," << p_up.y <<endl;
    // cout <<"--------------------down point "<< p_down.x << "," << p_down.y <<endl;
        if (this->position.isInTriangle(b->getPosition(),p_down,p_up,this->position)==true)
        {
            return true;
        }else{
            return false;
        }
    }

}

Vector2 Player::readyToKick(shared_ptr<Ball> &b)
{
    Vector2 goal(Constants::FIELDX,Constants::FIELDY/2);

    if(b->getFound()==true && b->isInGoal()==false && goal.x != (b->getPosition().x))
    {
        Vector2 target; 
        float k;
        k = ((float)(goal.y-b->getPosition().y))/(float)(goal.x -(b->getPosition().x));
        target.x = (int)(-Constants::KICKDISTANCE/sqrt(k*k+1)+b->getPosition().x);  
        if(k<0)
        {
            target.y = (int)(-Constants::KICKDISTANCE*k/sqrt(k*k+1)+b->getPosition().y);
        }else if (k>0)
        {
            target.y = (int)(-Constants::KICKDISTANCE*k/sqrt(k*k+1)+b->getPosition().y);
        }  
        
        //cout<<"--------------------ready to kick ponit "<<target.x << "," << target.y <<endl; 
        return target;  
    }else
    {
        return b->getPosition();
    }
}
