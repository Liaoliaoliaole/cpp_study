#include "circle.hpp"
#include "point.hpp"

circle::circle(float r)
	:point {x,y},radius{r=0.0}{
}

void circle::setRadius(float radius){
	this->radius=radius;
}
float circle::getRadius(){
	return this->radius;
}


