#include "point.hpp"

class circle 
	: public point{
public:
	float radius;
	
public:
	circle();
	circle(float r);
	~circle();
	void setRadius(float radius);
	float getRadius();
};
