#include "car.hpp"

class tesla : public car {
public:
    tesla();
    ~tesla();

    void setX(float x);
	void setY(float y);

    void accelerate();
    void brake();
	void move(float nx, float ny);
};