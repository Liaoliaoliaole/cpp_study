#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>
#include <memory>
#include "vehicle.hpp"
//#include "engineTypes.hpp"


class car :public vehicle {

public:
	car();
	car(const car &c);
	~car();	

	//void set_engine (engineTypes engine);
	//engineTypes get_engine();
	
	vehicleTypes get_types(void);
	//void set_type(vehicleTypes type);
	void accelerate(const double acceleration);
	void drive();
	//void go(const double distance);
};

#endif

