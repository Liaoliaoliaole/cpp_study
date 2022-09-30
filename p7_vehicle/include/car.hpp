#include <iostream>
#include <string>
#include "vehicle.hpp"


class car : public vehicle {
protected:
    std::string engine;

public:
	car();
	car(std::string brand, std::string engine, double speed);
	~car();	
	
	void set_engine (const std::string engine);
	std::string get_engine() const;

	void accelerate(const double acceleration);
	void go(const double distance);
};

