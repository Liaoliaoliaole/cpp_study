#include "ball.h"

Ball::Ball(){
    this->id = "B";
    this->position.x = 2400;
    this->position.y = 1650;
    this->found = true;

}

Ball::Ball(Vectr b, bool s){
    this->id = "B";
    this->position.x = b.x;
    this->position.y = b.y;
    this->found = s;

}

Ball::~Ball(){
}

bool Ball::getFound() {
    if(this->getPosition().x<=4800 && this->getPosition().x>=0 && this->getPosition().y<=3300 && this->getPosition().y>=0 ){
    return true;
    }else{
        return false;
    }
}
  
void Ball::setFound(bool status) {
    this->found = status;
}



  