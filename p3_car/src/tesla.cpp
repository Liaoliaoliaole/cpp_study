#include <cmath>
#include "tesla.hpp"

tesla::tesla(){
    this->brand = "Tesla";
    this->engine = "Battery";
    this->year = 0;
    this->speed = 0;
    this->full_tank_distance = 800;
    this->remain_distance = 800;
    this->x = 0;
    this->y = 0;
}

tesla::~tesla(){}

void tesla::setX(float x){
	this->x=x;
}
void tesla::setY(float y){
        this->y=y;
}

void tesla::accelerate(){
    this->speed += 10;
}
void tesla::brake(){
    if ((this->speed)>= 5)
            this->speed -= 5;
       else
            this->speed = 0;
}
void tesla::move(float nx, float ny){
    this->remain_distance -= sqrt(pow((nx-x),2)+pow((ny-y),2));
    this->x = nx;
    this->y = ny;
}