#include <iostream>
#include <string>
#include "bike.hpp"

#define MAXSPEED 40

bike::bike()
{
    this->wheels = 4;
	this->speed=0.0;
	this->brand = "Unnamed";
    std::cout << "Bike is created!" << std::endl;
}
bike::bike(std::string brand, double speed){
    this->wheels = 2;
	this->speed=speed;
	this->brand = brand;
    std::cout << "Bike object is created!" << std::endl;
}
bike::~bike(){
    std::cout << "Bike is distroyed!" << std::endl;
}

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
void bike::go(const double distance){
    if(distance >= 0 && distance < 50){
        std::cout << "Your bike takes " 
            << distance/this->speed 
            << "hours for the distance of " 
            << distance <<std::endl;
    }else if(distance >=50){
        std::cout << "Bon courage!" << std::endl;

    }else{
            std::cout << "Invalid distance!" << std::endl;
        }
}