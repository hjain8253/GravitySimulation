#include "Execute.h"
#include <iostream>


int main() {
    Execute* simulator = Execute::getInstance();
    simulator->build();

    double r = 7000000.0;      // Example radial distance in meters
    double phi = 0.523599;     // Example latitude in radians (30 degrees)
    double lambda = 0.0;       // Example longitude in radians
    simulator->calculate(r, phi, lambda);  // Acceleration calculation

    return 0;
}

