#include"vectr.h"

Vectr::Vectr(int i, int j) {
        this->x = i;  
        this->y = j;
}

Vectr::~Vectr(){
}

int Vectr::getX(){
        return this->x;
}

int Vectr::getY(){
        return this->y;
}

void Vectr::set(double x, double y){
    this->x=x;
    this->y=y;
}

Vectr Vectr::minus(Vectr &u, Vectr &v){  
    Vectr d(u.x-v.x, u.y-v.y);
    return d;
}
double Vectr::magnitude(){
    return sqrt(this->x * this->x + this->y *this->y);
}

void Vectr::multiply(double r) {
    this->x *= r;
    this->y *= r;
}

double Vectr::distanceToV2(Vectr &v){
    Vectr dv = minus(*this,v);
    return dv.magnitude();
}   

double Vectr::setMagnitude(double newM){
    double oldMag = magnitude();
    if (oldMag == 0){
        set(newM,0);
    }else{
        double m = newM/oldMag;
        multiply(m);
    }
    return oldMag;
}

Vectr Vectr::zeroVector(){
	Vectr zero(0,0);
	return zero;
}

string Vectr::printToCords()
    {
    return to_string(this->x) + "," + to_string(this->y) + "\n";
}