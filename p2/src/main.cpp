#include <iostream>
#include <memory>
#include "circle.hpp"

int main(int argc,char*argv[]){
	circle *c = new circle;
	/*c->setRadius(1.0);
	c->setX(1.0);
	c->setY(1.0);*/
	std::cout << "Circle c's radius: " << c->getRadius() << std::endl;
	std::cout << "Circle c's centre is: " << c->getX() << ", " << c->getY() << std::endl;
	delete c;
	std::cout << "-----------------------------------------------------" << std::endl;
	circle c1(1.0);
	circle &ref = c1;
	std::cout << "Circle c1's radius: " << c1.getRadius() << std::endl;
	std::cout << "Circle c1's centre is: " << c1.getX() << ", " << c1.getY() << std::endl;
	ref.setRadius(2.0);
	std::cout << "Ref changed. Circle c1's radius: " << c1.getRadius() << std::endl;
	std::cout << "Ref changed. Circle c1's centre is: " << c1.getX() << ", " << c1.getY() << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	/*shared pointers*/
	std::shared_ptr<circle> shared_circle (new circle(3.0));
	//shared pointer will create many pointer pointing to the circle object
	std::cout << "Circle shared_circle created by shared pointer: " << shared_circle->getRadius() << std::endl;
	shared_circle->setX(3.0);
	shared_circle->setY(3.0);
	std::cout << shared_circle->getX() << " " << shared_circle->getY() << std::endl;
	std::cout << "Number of shared pointer use: " << shared_circle.use_count() << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	std::shared_ptr<circle> shared_circle2;
	shared_circle2 = shared_circle;
	std::cout << "Circle shared_circle2 created by shared pointer: " << shared_circle2->getRadius() << std::endl;
	std::cout << "Number of shared pointer use: " << shared_circle.use_count() << std::endl;
	std::cout << "Number of shared pointer2 use: " << shared_circle2.use_count() << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	std::shared_ptr<circle> shared_circle3(new circle);//all 0 new circle
	std::cout << "Circle shared_circle3 created by shared pointer: " << shared_circle3->getRadius() << std::endl;
	shared_circle3 = shared_circle2;// from here the all 0 one above is disytoyed, pointing to new place.
	std::cout << "circle shared_circle3's radius is: " << shared_circle3->getRadius() << std::endl;
	shared_circle3->setRadius(4.0); // all shared circle become 4 radius
	std::cout << "Circle shared_circle's radius is " << shared_circle->getRadius() << "Circle shared_circle2's radius is "  << shared_circle2->getRadius() << "Circle shared_circle3's radius is " << shared_circle3->getRadius() << std::endl;
    std::cout << "Number of shared pointer use: " << shared_circle.use_count() << std::endl;
	std::cout << "Number of shared pointer2 use: " << shared_circle2.use_count() << std::endl;
	std::cout << "Number of shared pointer3 use: " << shared_circle3.use_count() << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	shared_circle = NULL;
	std::cout << "end of shared_circle" << std::endl;
	std::cout << "Number of shared pointer use: " << shared_circle.use_count() << std::endl;
	shared_circle2 =NULL;
	std::cout << "end of shared_circle2" << std::endl;
	std::cout << "Number of shared pointer2 use: " << shared_circle2.use_count() << std::endl;
	std::cout << "Number of shared pointer3 use: " << shared_circle3.use_count() << std::endl;
	//1.constructor with arguments, how to invoke base class's arguments. 
	//2. when shared_circle3 pointer is distroyed?
	    return 0;
}
