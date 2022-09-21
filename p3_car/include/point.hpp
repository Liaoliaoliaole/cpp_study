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
	virtual void setX(float x)=0;
	virtual void setY(float y)=0;
    float getX();
	float getY();
};
#endif
