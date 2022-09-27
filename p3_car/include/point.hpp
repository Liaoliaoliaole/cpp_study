#ifndef _POINT_H_
#define _POINT_H_
class point{
public:
	float x;
	float y;
	float zeta;// clamp with positive x-axis in 2D plane
public:
	point();
	point(float x, float y);
	~point();
	void setX(const float x);
	void setY(const float y);
	float getZeta(float x,float y);
	float getX() const;
	float getY() const;
};
#endif
