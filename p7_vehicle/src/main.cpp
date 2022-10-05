#include <iostream>
#include <memory>
#include <vector>

#include "vehicle.hpp"
#include "car.hpp"
#include "bike.hpp"


int main(int argc,char*argv[]){
	std::shared_ptr<vehicle> tesla1 = std::make_shared<car>("Tesla","Electrical",80.0);
	tesla1->accelerate(10);
	std::cout << tesla1->get_speed() << std::endl;

	std::shared_ptr<vehicle> helka1 = std::make_shared<bike>("Helkaman",25.0);
	helka1->accelerate(10);
	std::cout << helka1->get_speed() << std::endl;
	
	std::shared_ptr<vehicle> tesla2 = std::make_shared<car>("Tesla","Electrical",100.0);
	std::shared_ptr<vehicle> helka2 = std::make_shared<bike>("Helkaman",35.0);
	
	std::vector<std::shared_ptr<vehicle>> vehicles;
	vehicles.push_back(tesla1);
	vehicles.push_back(helka1);
	vehicles.push_back(tesla2);
	vehicles.push_back(helka2);


	for(auto &v : vehicles){
		std::cout << "============================" << std::endl;
		std::cout << v->get_brand() << " is at speed of " << v->get_speed() << std::endl;
		v->accelerate(5.0);
		std::cout << v->get_brand() << " after acceleration is at speed of " << v->get_speed() << std::endl;
		v->accelerate(15.0);
		std::cout << v->get_brand() << " after acceleration is at speed of " << v->get_speed() << std::endl;
		std::cout << "-----------------------------" << std::endl;
		v->go(30);
		std::cout << "-----------------------------" << std::endl;
		v->go(100);
		std::cout  << std::endl;
	}

std::cout << "**********************************************************" << std::endl;

	std::vector<std::shared_ptr<vehicle>>::iterator it;
	for(it=vehicles.begin(); it != vehicles.end();it++){
		std::cout << (*it)->get_brand() <<std::endl;
		std::cout << (*it)->get_speed() <<std::endl;
	}


	return 0;
}
