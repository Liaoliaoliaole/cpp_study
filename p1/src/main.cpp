#include <iostream>
#include "circle.hpp"

int main(int argc,char*argv[]){
	circle *c = new circle;
	c->setRadius(2.0);
	c->setX(1.0);
	c->setY(1.0);
	std::cout << c->getRadius() << std::endl;
	std::cout << c->getX() << ", " << c->getY() << std::endl;
	delete c;	
return 0;
}
