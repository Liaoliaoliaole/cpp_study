#ifndef _POINT_H_
#define _POINT_H_
class point{
public:
	float x;
	float y;
public:
	point();
	point(float xv, float yv);
	~point();
	void setX(float x);
	void setY(float y);
    float getX();
	float getY();
};
#endif