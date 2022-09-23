#include "car.hpp"

class tesla : public car {
public:
    tesla();
    ~tesla();

    void accelerate();
    void brake();
	void move(float nx, float ny);
    float timeConsuming(float distance);
};