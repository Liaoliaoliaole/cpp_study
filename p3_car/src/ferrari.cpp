#include <iostream>

#include "ferrari.hpp"

ferrari::ferrari(){
    this->brand = "Ferrari";
    this->engine = "gasoline";
    this->year = 0;
    this->speed = 80;
    this->full_tank_distance = 1000;
    this->remain_distance = 1000;
    this->x = 0;
    this->y = 0;
    std::cout << "Ferrari is created!" << std::endl;
}

ferrari::~ferrari(){
    std::cout << "Ferrari is distroyed!" << std::endl;
}

void ferrari::accelerate(){
    this->speed += 20;
}
void ferrari::brake(){
    if ((this->speed)>= 4)
            this->speed -= 4;
       else
            this->speed = 0;
}
