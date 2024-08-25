#include "Legendre.h"
#include <iostream>
using namespace std;
Legendre::Legendre(int max_n, double x_val) : P(max_n + 1, std::vector<double>(max_n + 1, 0.0)), x(x_val) {
	//setting initial values for table
	P[0][0] = 1;
	P[1][0] = x_val;
	P[1][1] = -std::sqrt(1 - std::pow(x_val,2));

/*	cout << "n = " << 0 << "m = " << 0  << "P[n][m] = " << P[0][0] << endl;
	cout << "n = " << 1 << "m = " << 0  << "P[n][m] = " << P[1][0] << endl;
	cout << "n = " << 1 << "m = " << 1  << "P[n][m] = " << P[1][1] << endl;
*/
}

double Legendre::calculatePnm(int n, int m) {
	//check outlier cases
    if (m < 0 || m > n) {
        throw std::invalid_argument("Invalid m value for the given n");
    }
    if (n == 0 && m == 0) {
        return P[0][0];
    }
    if (P[n][m] != 0.0) {
        return P[n][m];
    }
	//check for three conditional cases 
    if (n == m) {
        P[n][m] = (-1) * (2 * m - 1) * P[n - 1][m - 1] * std::sqrt(1 - x * x);
    } else if (n == m + 1) {
        P[n][m] = (2 * n - 1) * x * P[n - 1][m];
    } else {
        P[n][m] = ((2 * n - 1) * x * P[n - 1][m] - (n + m - 1) * P[n - 2][m]) / (n - m);
    }
	//comment out below for debugging
    //std::cout << "n = " << n << " m = " << m << " P[n][m] = " << P[n][m] << std::endl;
    return P[n][m];
}
