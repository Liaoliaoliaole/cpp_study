#include <iostream>
#include <string>
#include "car.hpp"

#define MAXSPEED 200

car::car()
{
    double speed = 0;
	std::string brand = "unknown";
	vehicleTypes type = vehicleTypes::car;
    std::cout << "Car created!" << std::endl;
}
car::car(const car &c):vehicle(c){
    std::cout << "Car copied!" << std::endl;
}
car::~car(){
    std::cout << "Car distroyed!" << std::endl;
}
vehicleTypes car::get_types(void){
    return vehicleTypes::car;
}
//void car::set_type(vehicleTypes type){
//    this->type=type;
//}

void car::accelerate(const double acceleration){
    if (this->speed <= (MAXSPEED-acceleration))
    {
        this->speed += acceleration;
    }else{
        std::cout << "Invalid acceleration!" << std::endl;
    }
}
void car::drive(){
        std::cout << "Vrooommmm..." << std::endl;
}