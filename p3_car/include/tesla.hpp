#include "car.hpp"

class tesla : public car {
public:
    tesla();
    ~tesla();

    void accelerate();
    void brake();
};