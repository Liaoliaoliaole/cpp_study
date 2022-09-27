#include <iostream>
#include <memory>
#include <vector>

#include "tesla.hpp"
#include "ferrari.hpp"
#include "kia.hpp"

#define PI 3.1415926

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
	auto shared_car_k = std::make_shared<kia>();
	std::shared_ptr<kia> k2 (new kia);
	shared_car_k=k2;//does this distroy k2?
	std::cout << "SharedK Use count: " << shared_car_k.use_count() << std::endl;
	
	k2->setX(4.0);
	k2->setY(4.0);
	std::cout << "The direction of k2 is  " << k2->getZeta(4.0,4.0) << std::endl;
	k2->move(150.3,160.4);
	std::cout << "The direction of k2 is  " << k2->getZeta(150.3,160.4) << std::endl;
	k2->brake();
	std::cout << "Shared Kia: " << k2->getX() << ", " << k2->getY();
	std::cout << " has a speed of " << shared_car_k->get_speed() << " and a remain distance of " << shared_car_k->remain_distance << std::endl;
	std::cout << "===========================================================" << std::endl;

	std::shared_ptr<tesla> t2 (new tesla);
	std::shared_ptr<kia> k1 (new kia);
	shared_car_k=k1;
	//k2=k1 not work
	shared_car_t=t2;
	std::cout << "SharedK Use count: " << shared_car_k.use_count() << std::endl;
	std::cout << "SharedT Use count: " << shared_car_t.use_count() << std::endl;
	std::cout << "===========================================================" << std::endl;

	std::vector<std::shared_ptr<car>> cars;
	cars.push_back(shared_car_t);
	cars.push_back(shared_car_f);
	cars.push_back(shared_car_k);
	
	std::cout << "SharedT Use count: " << shared_car_t.use_count() << std::endl;
	std::cout << "SharedF Use count: " << shared_car_f.use_count() << std::endl;
	std::cout << "SharedK Use count: " << shared_car_k.use_count() << std::endl;

	for(const auto &shared_car : cars){
		std::cout << shared_car->get_brand()  << std::endl;
		std::cout << "Use count: " << shared_car.use_count() << std::endl;
	}
	std::cout << "===========================================================" << std::endl;
	auto t4 = std::make_unique <tesla>();
	t4->setX(8.0);
	t4->setY(6.0);
	t4->accelerate();
	shared_car_t = std::move(t4);
	std::cout << "SharedT Use count: " << shared_car_t.use_count() << std::endl;
	//std::cout << "t4 unique ptr Use count: " << t4.use_count() << std::endl;
	

	    return 0;
}
