#ifndef MAGNETIC_FIELD_H
#define MAGNETIC_FIELD_H

#include "Field.h"
#include <iostream>
#include <cmath>

const double MU_0 = 4.0 * M_PI * 1e-7; 

class Magnetic_Field : public Field {
private:
    double calculated_B;

public:
    Magnetic_Field() : Field(), calculated_B(0.0) {}

    Magnetic_Field(double x, double y, double z) : Field(x, y, z), calculated_B(0.0) {}

    void calculateBField(double I, double r) {
        //prevent r=0 like in E-field
        if (r > 0) {
            calculated_B = (MU_0 * I) / (2.0 * M_PI * r);
        } else {
            calculated_B = 0.0;
        }
    }

    double getCalculatedB() const { return calculated_B; }

    Magnetic_Field operator+(const Magnetic_Field &rhs) const {
        Magnetic_Field result(this->value[0] + rhs.value[0], 
                              this->value[1] + rhs.value[1], 
                              this->value[2] + rhs.value[2]);
        return result;
    }

    friend std::ostream& operator<<(std::ostream &os, const Magnetic_Field &m);
};

inline std::ostream& operator<<(std::ostream &os, const Magnetic_Field &m) {
    os << "B-Field [" << m.getComponent(0) << ", " << m.getComponent(1) << ", " << m.getComponent(2) << "]";
    return os;
}

#endif