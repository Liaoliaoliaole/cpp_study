#include <iostream>
#include <string>
#include "vehicle.hpp"

class bike : public vehicle {


public:
    enum engine_type {MAN,ELE};
	bike();
    bike(std::string brand, double speed);
	~bike();	
	
	void accelerate(const double acceleration);
    void go(const double distance);
};