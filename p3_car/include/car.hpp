
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
	//car(int year, string brand);
	~car();
	
	std::string get_brand();
	std::string get_engine();
	int get_year();
	float get_speed();
	float get_full_tank_distance();
	float get_remain_distance();

	void set_brand(std::string brand);
	void set_engine(std::string engine);
	void set_year(int year);
	void set_speed(float speed);
	void set_full_tank_distance(float ftd);


	virtual void accelerate() =0;
    virtual void brake() = 0;
	virtual void move(float nx, float ny) = 0;
};
