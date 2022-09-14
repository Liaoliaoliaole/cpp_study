#include "point.hpp"

point::point(float xv , float yv )
	:x{xv =0.0},y{yv=0.0}{
}

void point::setX(float x){
	this->x=x;
}
void point::setY(float y){
        this->y=y;
}
float point::getX(){
	return this->x;
}
float point::getY(){
	return this->y;
}
