#include "ball.h"

Ball::Ball(){
    this->id = "B";
    this->position.x = 2400;
    this->position.y = 1650;
    this->found = true;

}

Ball::Ball(Vectr b, bool s){
    this->id = "B";
    this->position.x = b.getX();
    this->position.y = b.getY();
    this->found = s;

}

// Ball::Ball(map<string,Vectr> cords){
//     for(auto it = cords.cbegin(); it != cords.cend(); ++it){
//     if(it->first == "B"){
//         this->id = it->first;
//         this->position.x=it->second.x;
//         this->position.y=it->second.y;
//     }
//     }
// }

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

Vectr Ball::readyToKick(Vectr &b)
{
    return b;
}

//void Ball::move(map<string,Vectr> cords,Vectr &b, shared_ptr<Socket> &sock){}


  