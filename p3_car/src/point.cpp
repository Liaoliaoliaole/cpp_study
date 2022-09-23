#include <iostream>
#include "point.hpp"

point::point(){
	this->x=0;
	this->y=0;
}

point::point(float x , float y){
	this->x=x;
	this->y=y;
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
float point::getX() const{
	return this->x;
}
float point::getY()const {
	return this->y;
}
