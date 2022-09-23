
#ifndef _CAR_H_
#define _CAR_H_

#include <string>
#include "point.hpp"

class car : public point {
public:
	std::string brand,
	            engine;
	int year;
	float speed,
	      full_tank_distance,
		  remain_distance;

public:
	car();
	~car();	
	std::string get_brand() const;
	std::string get_engine()const;
	int get_year()const;
	float get_speed()const;
	float get_full_tank_distance()const;
	float get_remain_distance();
	void set_brand(const std::string brand);
	void set_engine(const std::string engine);
	void set_year(const int year);
	void set_speed(const float speed);
	void set_full_tank_distance(const float ftd);


	virtual void accelerate() = 0;
    virtual void brake() = 0;

	void move(float nx, float ny);	
    float timeConsuming(float distance);
};
#endif
