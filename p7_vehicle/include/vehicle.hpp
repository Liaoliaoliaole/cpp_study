#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <iostream>
#include <string>
//const char *engine_types []={"none","gasoline","desile","electrical","hybrid"};

class vehicle{	
protected:
	int wheels;
	double speed;
	std::string brand;

public:
	vehicle();
	~vehicle();

	std::string get_brand()const;
	int get_wheels() const;	
	double get_speed() const;
	void set_brand(const std::string brand);
	void set_speed(const double speed);
	virtual void accelerate(const double acceleration);
	virtual void go(const double distance);
};
#endif
