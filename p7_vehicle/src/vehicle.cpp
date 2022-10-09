#include <iostream>
#include <cmath>
#include "vehicle.hpp"

vehicle::vehicle()
{
	double speed = 0;
	std::string brand = "unknown";
	vehicleTypes type = vehicleTypes::NONE;
	std::cout << "Vehicle created" << std::endl;
}
std::string vehicle::get_brand()const{
	return this->brand;
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
