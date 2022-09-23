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
car::~car(){
    std::cout << "Car is distroyed!" << std::endl;
}
	
std::string car::get_brand()const{return this->brand;}
std::string car::get_engine()const{return this->engine;}
int car::get_year()const{return this->year;}
float car::get_speed()const{return this->speed;}
float car::get_full_tank_distance()const{return this->full_tank_distance;}
float car::get_remain_distance(){return this->remain_distance;}

void car::set_brand(const std::string brand){this->brand=brand;}
void car::set_engine(const std::string engine){this->engine=engine;}
void car::set_year(const int year){this->year=year;}
void car::set_speed(const float speed){this->speed = speed;}
void car::set_full_tank_distance(const float ftd){this->full_tank_distance = ftd;}

