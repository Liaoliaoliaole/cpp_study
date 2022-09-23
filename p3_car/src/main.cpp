#include <iostream>
#include <memory>
#include <vector>

#include "tesla.hpp"
#include "ferrari.hpp"
#include "kia.hpp"

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
	std::cout << "===========================================================" << std::endl;
	ferrari f1;
	ferrari &f_ref = f1;
	f_ref.set_year(2000);
	f1.setX(3);
	f1.setY(3);
	std::cout << "Ferrari f1: Brand: " << f1.get_brand() << " Engine: " << f1.get_engine() << " Year: " << f1.get_year() << std::endl;
	std::cout << "It locates at " << f_ref.getX() << ", " << f_ref.getY() << std::endl;
	std::cout << "===========================================================" << std::endl;
	std::shared_ptr<car> shared_car_t = std::make_shared<tesla>();
	std::shared_ptr<car> shared_car_f = std::make_shared<ferrari>();
	std::shared_ptr<car> shared_car_k = std::make_shared<kia>();
	std::shared_ptr<kia> k2 (new kia);
	shared_car_k=k2;
	k2->setX(4.0);
	k2->setY(4.0);
	k2->move(150.3,160.4);
	k2->brake();
	std::cout << "Shared Kia: " << k2->getX() << ", " << k2->getY();
	std::cout << " has a speed of " << shared_car_k->get_speed() << " and a remain distance of " << shared_car_k->remain_distance << std::endl;
	
	std::shared_ptr<tesla> t2 (new tesla);
	std::shared_ptr<tesla> t3 (new tesla);
	std::shared_ptr<kia> k1 (new kia);
	shared_car_k=k1;
	//k2=k1 not counting
	shared_car_t=t2;
	shared_car_t=t3;

	std::vector<std::shared_ptr<car>> cars;
	cars.push_back(shared_car_t);
	cars.push_back(shared_car_f);
	cars.push_back(shared_car_k);
	
	for(const auto &shared_car : cars){
		std::cout << shared_car->get_brand()  << std::endl;
		std::cout << "Use count: " << shared_car.use_count() << std::endl;
	}
	    return 0;
}
