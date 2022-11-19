#include <cmath>
#include <string>
#include "vector2.h"

Vector2::Vector2(int i, int j) {
        this->x = i;  
        this->y = j;
}

Vector2::Vector2(const Vector2 &v){
    this->x = v.x;
    this->y = v.y;

}

Vector2::~Vector2(){
}


Vector2 Vector2::minus(Vector2 &u, Vector2 &v){  
    Vector2 d(u.x-v.x, u.y-v.y);
    return d;
}
double Vector2::getMagnitude(){
    return sqrt(this->x * this->x + this->y *this->y);
}

double Vector2::distanceToV2(Vector2 &v){
    Vector2 dv = minus(*this,v);
    return dv.getMagnitude();
} 

double Vector2::product(Vector2 &p1,Vector2 &p2,Vector2 &p3) 
{
    //vector p1p2 is (p2.x-p1.x,p2.y-p1.y)
    //vector p1p3 is (p3.x-p1.x,p3.y-p1.y)
    //cross product
    return (p2.x-p1.x)*(p3.y-p1.y) - (p2.y-p1.y)*(p3.x-p1.x);
}

bool Vector2::isInTriangle(Vector2 p1,Vector2 p2,Vector2 p3,Vector2 o) {
    //p1,p2,p3 must be in counterclockwise order
    if(product(p1, p2, p3)<0)
    {
         return isInTriangle(p1,p3,p2,o);
    }
    //vector o must be on the left of any p1p2,p2p3,p3p1 vectors
    if(product(p1, p2, o)>=0 && product(p2, p3, o)>=0 && product(p3, p1, o)>=0)
    {
        return true;
    }
    return false;
}

  

