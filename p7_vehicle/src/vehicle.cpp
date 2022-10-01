#include <iostream>
#include <cmath>
#include "vehicle.hpp"

vehicle::vehicle()
{
	this->wheels = 0;
	this->speed=0.0;
	this->brand = "Unnamed";
	std::cout << "Vehicle is created" << std::endl;
}
vehicle::~vehicle(){
	std::cout << "Vehicle is distroyed" << std::endl;
}

//void vehicle::set_wheels(const int wheels){
//	this->wheels = wheels;
//	}
std::string vehicle::get_brand()const{
	return this->brand;
}
int vehicle::get_wheels() const{
	return this->wheels;
}
double vehicle::get_speed() const{
	return this->speed;
}
void vehicle::set_brand(const std::string brand){
	this->brand=brand;
}
void vehicle::set_speed(const double speed){
	this->speed = speed;
}
 void vehicle::accelerate(const double acceleration){
	std::cout<< "Vehicle accelerated!" << std::endl;
}

void vehicle::go(const double distance){
	std::cout<< "Vehicle goes!" << std::endl;
}
