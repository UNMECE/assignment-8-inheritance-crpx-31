#ifndef ELECTRIC_FIELD_H
#define ELECTRIC_FIELD_H

#include "Field.h"
#include <iostream>
#include <cmath>

const double EPSILON_0 = 8.854e-12; 

class Electric_Field : public Field {
private:
    double calculated_E;

public:
    Electric_Field() : Field(), calculated_E(0.0) {}

    Electric_Field(double x, double y, double z) : Field(x, y, z), calculated_E(0.0) {}

    void calculateEField(double Q, double r) {
        //catch r=0 so dont divide by 0 and crash
        if (r > 0) {
            calculated_E = Q / (4.0 * M_PI * r * r * EPSILON_0);
        } else {
            calculated_E = 0.0; 
        }
    }

    double getCalculatedE() const { return calculated_E; }

    //return new object to protect og
    Electric_Field operator+(const Electric_Field &rhs) const {
        Electric_Field result(this->value[0] + rhs.value[0], 
                              this->value[1] + rhs.value[1], 
                              this->value[2] + rhs.value[2]);
        return result;
    }

    //friend so << can access private members
    friend std::ostream& operator<<(std::ostream &os, const Electric_Field &e);
};

//return 'os' for output chaining
inline std::ostream& operator<<(std::ostream &os, const Electric_Field &e) {
    os << "E-Field [" << e.getComponent(0) << ", " << e.getComponent(1) << ", " << e.getComponent(2) << "]";
    return os;
}

#endif