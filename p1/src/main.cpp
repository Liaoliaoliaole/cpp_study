#include <iostream>
#include "circle.hpp"

int main(int argc,char*argv[]){
	circle c1;
	c1.setRadius(2.0);
	c1.setX(1.0);
	c1.setY(1.0);
	std::cout << c1.getRadius() << " " << c1.getX() << " " << c1.getY() << std::endl;
	return 0;
}
