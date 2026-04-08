#include <iostream>

#include "Electric_Field.h"
#include "Magnetic_Field.h"

int main() {
    Electric_Field e1(0, 1e5, 1e3);
    Electric_Field e2(100, 2e5, 500);
    
    Magnetic_Field m1(0.5, 0.0, 1.2);
    Magnetic_Field m2(0.1, 0.1, 0.5);

    std::cout << "Starting values:" << std::endl;
    std::cout << "Electric field 1 | ";
    e1.printMagnitude();
    std::cout << "Magnetic field 1 | ";
    m1.printMagnitude();
    std::cout << std::endl;

    double charge = 1.5e-6; 
    double distance_E = 0.05; 
    e1.calculateEField(charge, distance_E);

    double current = 10.0; 
    double distance_B = 0.02; 
    m1.calculateBField(current, distance_B);

    std::cout << "Calculated outputs: " << std::endl;
    std::cout << "E-Field from point charge (Q=" << charge << "C, r=" << distance_E << "m): " 
              << e1.getCalculatedE() << " V/m" << std::endl;
    std::cout << "B-Field from wire (I=" << current << "A, r=" << distance_B << "m): " 
              << m1.getCalculatedB() << " T" << std::endl;
    std::cout << std::endl;

    //validate deep copy;will crash here if broken
    Electric_Field e3 = e1 + e2;
    Magnetic_Field m3 = m1 + m2;

    std::cout << "Checking the operators:" << std::endl;
    std::cout << "e1: " << e1 << std::endl;
    std::cout << "e2: " << e2 << std::endl;
    std::cout << "e1 + e2 = " << e3 << std::endl << std::endl;

    std::cout << "m1: " << m1 << std::endl;
    std::cout << "m2: " << m2 << std::endl;
    std::cout << "m1 + m2 = " << m3 << std::endl;

    return 0;
}