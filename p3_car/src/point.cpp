#include <iostream>
#include <cmath>
#include "point.hpp"

#define PI 3.1415926

point::point(){
	this->x=0;
	this->y=0;
	this->zeta=0;
	std::cout << "point object created" << std::endl;
}

point::point(float x , float y){
	this->x=x;
	this->y=y;
	this->zeta= atan(y/x)*180/PI;
	std::cout << "point object with XY created" << std::endl;
}
point::~point(){
	std::cout << "point is distroyed" << std::endl;
}
void point::setX(const float x){
	this->x = x;
}
void point::setY(const float y){
	this->y = y;
}

float point::getZeta(float x, float y){
	this->zeta=atan(y/x)*180/PI;
	return this->zeta;
}
float point::getX() const{
	return this->x;
}
float point::getY()const {
	return this->y;
}

