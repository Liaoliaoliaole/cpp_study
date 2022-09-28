#include <iostream>
#include "circle.hpp"
#include "point.hpp"

circle::circle(){
	this->radius = 0; 
}

circle::circle(float r){
	this->radius=r;
}

circle::~circle(){
	std::cout << "circle distroyed" << std::endl;
}

void circle::setRadius(float radius){
	this->radius=radius;
}
float circle::getRadius(){
	return this->radius;
}


