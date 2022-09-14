#include "point.hpp"

class circle 
	: public point{
public:
	float radius;
	
public:
	circle(float r =0 );
	void setRadius(float radius);
	float getRadius();
};
