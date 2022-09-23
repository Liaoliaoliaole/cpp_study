#include <iostream>
#include <cmath>
#include "tesla.hpp"

tesla::tesla(){
    this->brand = "Tesla";
    this->engine = "Battery";
    this->year = 0;
    this->speed = 60;
    this->full_tank_distance = 800;
    this->remain_distance = 800;
    this->x = 0;
    this->y = 0;
}

tesla::~tesla(){
    std::cout << "Tesla is distroyed!" << std::endl;
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

float tesla::timeConsuming(float distance){
    if (distance > this->full_tank_distance){
        std::cout << "Invalid distance!" << std::endl;
        exit(1);
    }else {
        return distance/this->speed;
    }
}