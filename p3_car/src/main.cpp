#include <iostream>
#include <memory>
#include "tesla.hpp"

int main(int argc,char*argv[]){
	tesla t1;
	std::cout  << t1.get_brand() << std::endl;
	std::cout << "Tesla t1 now is at " << t1.getX() << ", " << t1.getY() << std::endl;
	std::cout << "Tesla t1's speed is: " << t1.get_speed() << std::endl;
	t1.accelerate();
	t1.accelerate();
	t1.brake();
	std::cout << "Tesla t1's speed after twice accelerating and one brake is: " << t1.get_speed() << std::endl;
	t1.move(3.0,4.0);
	std::cout << "Tesla t1 has moved " << t1.full_tank_distance - t1.remain_distance << std::endl;
	std::cout << "t1 has spent " << t1.timeConsuming(t1.full_tank_distance - t1.remain_distance) << " time." << std::endl;
	t1.accelerate();
	std::cout << "t1 will spend " << t1.timeConsuming(t1.remain_distance) << " time to empty the battary." << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	/*
	circle c1(1.0);
	circle &ref = c1;
	std::cout << "Circle c1's radius: " << c1.getRadius() << std::endl;
	std::cout << "Circle c1's centre is: " << c1.getX() << ", " << c1.getY() << std::endl;
	ref.setRadius(2.0);
	std::cout << "Ref changed. Circle c1's radius: " << c1.getRadius() << std::endl;
	std::cout << "Ref changed. Circle c1's centre is: " << c1.getX() << ", " << c1.getY() << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;

	std::shared_ptr<circle> shared_circle (new circle(3.0));
	
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

	std::cout << "-----------------------------------------------------" << std::endl;
	std::shared_ptr<point> sc1 = std::make_shared<circle>();
	std::shared_ptr<point> sc2 = std::make_shared<circle>(20);
	//std::shared_ptr<point> sc3 = std::make_shared<circle>(30,30,30);
	
	std::vector<std::shared_ptr<point>> circles;
        circles.push_back(sc1);
        circles.push_back(sc2);
        //circles.push_back(sc3);
    
        for (const auto &sc: circles) {
        std::cout << sc->getX() << sc->getY() << std::endl;
        std::cout << "Use count: " << sc.use_count() << std::endl;
        }
	//1.constructor with arguments, how to invoke base class's arguments. 
	//2. when shared_circle3 pointer is distroyed?*/
	    return 0;
}
