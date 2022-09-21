#include <iostream>
#include <string>
#include "car.hpp"

car::car(){
    this->brand= "";
    this->engine= "";
    this->year=0;
    this->speed=0;
    this->full_tank_distance=0;
    this->remain_distance = 0;
    this->x=0;
    this->y=0;
}
/*car::car(int year, string brand){
    this->year = year;
    this->brand = brand;
}*/
car::~car(){}
	
std::string car::get_brand(){return this->brand;}
std::string car::get_engine(){return this->engine;}
int car::get_year(){return this->year;}
float car::get_speed(){return this->speed;}
float car::get_full_tank_distance(){return this->full_tank_distance;}
float car::get_remain_distance(){return this->remain_distance;}

void car::set_brand(std::string brand){this->brand=brand;}
void car::set_engine(std::string engine){this->engine=engine;}
void car::set_year(int year){this->year=year;}
void car::set_speed(float speed){this->speed = speed;}
void car::set_full_tank_distance(float ftd){this->full_tank_distance = ftd;}
//cars::void set_positions(float x, float y){
//    this->x=x;
//    this->y=y;
//}
