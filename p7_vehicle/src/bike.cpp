#include <iostream>
#include <string>
#include "bike.hpp"

#define MAXSPEED 40

bike::bike()
{
    double speed = 0;
	std::string brand = "unknown";
	vehicleTypes type = vehicleTypes::bike;
    std::cout << "Bike created!" << std::endl;
}
bike::~bike(){
    std::cout << "Bike distroyed!" << std::endl;
}
vehicleTypes bike::get_types(void){
    return vehicleTypes::bike;
}
//void bike::set_type(vehicleTypes type){
//    this->type=type;
//}
void bike::accelerate(const double acceleration){
    if(acceleration >=0.0){
        if (this->speed <= (MAXSPEED-acceleration))
        {
            this->speed += acceleration;
        }else{
            std::cout << "Invalid acceleration!" << std::endl;
        }
    } else {
        if(this->speed >= acceleration*(-1)){
            this->speed += acceleration;
        }else{
            std::cout << "Invalid acceleration!" << std::endl;
        }
    }
}
void bike::pedal(){
        std::cout << "Pfffff....." << std::endl;
}