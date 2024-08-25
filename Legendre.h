#ifndef LEGENDRE_H
#define LEGENDRE_H

#include <vector>
#include <cmath>

//Legendre class calculates the Legendre coefficient for every n and m.
//A 2d vector table is used for dynamic programming to improve efficiency.  

class Legendre {
public:
    std::vector<std::vector<double> > P;
    Legendre(int max_n, double x_val);
	double x;
    double calculatePnm(int n, int m);
};

#endif
