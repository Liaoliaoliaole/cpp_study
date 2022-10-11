#ifndef _BIKE_H_
#define _BIKE_H_

#include <iostream>
#include <string>
#include "vehicle.hpp"

class bike :public vehicle {

public:
	bike();
	~bike();	

	vehicleTypes get_types(void);
	void accelerate(const double acceleration);
    void pedal();
};

#endif