#include <iostream>

#include "kia.hpp"

kia::kia(){
    this->brand = "KIA";
    this->engine = "gasoline";
    this->year = 0;
    this->speed = 50;
    this->full_tank_distance = 700;
    this->remain_distance = 700;
    this->x = 0;
    this->y = 0;
    std::cout << "Kia is created!" << std::endl;
}
kia::~kia(){
    std::cout << "Kia is distroyed!" << std::endl;
}

void kia::accelerate(){
    this->speed += 5;
}
void kia::brake(){
    if ((this->speed)>= 8)
            this->speed -= 8;
       else
            this->speed = 0;
}
