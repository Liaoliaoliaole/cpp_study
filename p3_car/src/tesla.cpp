#include <iostream>
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
