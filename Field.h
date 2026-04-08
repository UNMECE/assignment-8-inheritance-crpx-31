#ifndef FIELD_H
#define FIELD_H

#include <iostream>

class Field {
protected:
    double *value; 

public:
    Field() {
        value = new double[3];
        value[0] = 0.0;
        value[1] = 0.0;
        value[2] = 0.0;
    }

    Field(double x, double y, double z) {
        value = new double[3];
        value[0] = x;
        value[1] = y;
        value[2] = z;
    }

    //deep copy pointer to avoid doubledelete segfault
    Field(const Field &other) {
        value = new double[3];
        value[0] = other.value[0];
        value[1] = other.value[1];
        value[2] = other.value[2];
    }

    //prevents obj = obj from deleting its own data..
    Field& operator=(const Field &other) {
        if (this != &other) { 
            value[0] = other.value[0];
            value[1] = other.value[1];
            value[2] = other.value[2];
        }
        return *this;
    }

    ~Field() {
        // delete[] needed for arrays
        delete[] value; 
    }

    void printMagnitude() const {
        std::cout << "Components: [" << value[0] << ", " << value[1] << ", " << value[2] << "]" << std::endl;
    }

    double getComponent(int index) const {
        if (index >= 0 && index < 3) return value[index];
        return 0.0;
    }
};

#endif