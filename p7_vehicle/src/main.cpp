#include <iostream>
#include <memory>
#include <vector>
#include <iterator>
#include <list>
#include <exception>

#include "vehicleTypes.hpp"
#include "vehicle.hpp"
#include "car.hpp"
#include "bike.hpp"



int main(int argc,char*argv[]){
	auto c1 = std::make_shared<car>();
	auto b1 = std::make_shared<bike>();
	auto c2 = std::make_shared<car>();
	auto b2 = std::make_shared<bike>();

	c1->set_brand("Tesla");
	b1->set_brand("Helkama");
	c2->set_brand("Volvo");
	b2->set_brand("Cube");
	
	std::list<std::shared_ptr<vehicle>> vehicles;
	vehicles.push_back(c1);
	vehicles.push_back(b1);
	vehicles.push_back(c2);
	vehicles.push_back(b2);

	std::cout << "**********************************************************" << std::endl;

	for(auto &v : vehicles){
		std::cout  << v->get_brand();
		v->accelerate(35.0);
		std::cout << " is at speed of " << v->get_speed() << std::endl;

		if(v->get_types()==vehicleTypes::car){
			std::shared_ptr<car> c = std::dynamic_pointer_cast<car>(v);
			c->drive();
		}else if (v->get_types()==vehicleTypes::bike){
			std::shared_ptr<bike> b = std::dynamic_pointer_cast<bike>(v);
			b->pedal();
		}

		std::cout  << v->get_brand();
		v->accelerate(35.0);
		std::cout << " is at speed of " << v->get_speed() << std::endl;
	}

	std::cout << "**********************************************************" << std::endl;

	std::list<std::shared_ptr<vehicle>>::iterator it;

	it=vehicles.begin();
	for(int i{0};i<vehicles.size()/2;++i){
		++it;
	}//mid place
	auto c3 = std::make_shared<car>();
	c3->set_brand("Toyota");
	vehicles.insert(it,c3);

	for(it=vehicles.begin(); it != vehicles.end();it++){
		if((*it)->get_types()==vehicleTypes::car){
			//why cast fail?
			//car &c = static_cast <car> (**it);
			//c.drive();
			std::shared_ptr<car> c = std::dynamic_pointer_cast<car>(*it);
			std::cout << c->get_brand();
			c->drive();	
		}else{
			std::cout << "Oooops..." << std::endl;
		}
	}

std::cout << "**********************************************************" << std::endl;

//Exception
for(auto &v : vehicles){
	if(v->get_types()!=vehicleTypes::car){
		throw "Not a car!";
	}
	std::shared_ptr<car> c = std::dynamic_pointer_cast<car>(v);
	std::cout << c->get_brand();
	c->drive();	
try
{
	
}
catch(...)
{
	std::shared_ptr<bike> b = std::dynamic_pointer_cast<bike>(v);
	b->pedal();
}
catch(const std::exception& e)
{
	std::cerr << e.what() << '\n';
}
}



	return 0;
}
