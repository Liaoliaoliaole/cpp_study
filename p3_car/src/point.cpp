#include <iostream>
#include "point.hpp"

point::point(){
	this->x=0;
	this->y=0;
}

point::point(float xv , float yv ){
	this->x=xv;
	this->y=yv;
}


point::~point(){
	std::cout << "point distroyed" << std::endl;
}

float point::getX(){
	return this->x;
}
float point::getY(){
	return this->y;
}
