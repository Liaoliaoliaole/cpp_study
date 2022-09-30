#include <iostream>
#include <string>
#include "car.hpp"

#define MAXSPEED 200

car::car()
{
    this->wheels = 2;
	this->speed=0.0;
	this->brand = "Unnamed";
    this->engine = "Undefined";
    std::cout << "Car is created!" << std::endl;
}
car::car(std::string brand, std::string engine, double speed){
    this->wheels = 2;
	this->speed=speed;
	this->brand = brand;
    this->engine = engine;
    std::cout << "Car object is created!" << std::endl;
}
car::~car(){
    std::cout << "Car is distroyed!" << std::endl;
}
std::string car::get_engine()const{
    return this->engine;
    }
void car::set_engine(const std::string engine){
    this->engine = engine;
    }

void car::accelerate(const double acceleration){
    if (this->speed <= (MAXSPEED-acceleration))
    {
        this->speed += acceleration;
    }else{
        std::cout << "Invalid acceleration!" << std::endl;
    }
}
void car::go(const double distance){
    std::cout << "Your car takes " 
        << distance/this->speed 
        << "hours for the distance of " 
        << distance <<std::endl;
}