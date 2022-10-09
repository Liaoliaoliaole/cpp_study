#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <iostream>
#include <string>
#include <vehicleTypes.hpp>

class vehicle{	
protected:
	double speed;
	std::string brand;
	vehicleTypes type;

public:
	vehicle();
	virtual ~vehicle()=default;

	std::string get_brand()const;
	double get_speed() const;
	virtual vehicleTypes get_types(void)=0;

	void set_brand(const std::string brand);
	void set_speed(const double speed);
	//virtual void set_type(vehicleTypes v)=0;

	virtual void accelerate(const double acceleration)=0;
	//virtual void go(const double distance)=0;
};
#endif
