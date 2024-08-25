#ifndef EXECUTE_H
#define EXECUTE_H

#include <string>
#include <vector>
#include "Order.h"
#include "Legendre.h"

//Execute class is used to implement the simulation.

class Execute {
public:
    const std::string filename;
    std::vector<Order*> n_orders;
    static Execute* getInstance();
    void build(); //reads from EMG2008 data and stores into defined data structures
    void calculate(double r, double phi, double lambda); // calls calculatePotential and calculateAcceleration
	double calculatePotential(double r, double phi, double lambda); // calculates the gravitational potential
	void calculateAcceleration(double r, double phi, double lambda, double& ax, double& ay, double& az); //acc

private:
    Execute();
    static Execute* mExecute;
	static constexpr double R = 6378137.0; // Earth's radius in meters
    static constexpr double GM = 3.986004418e14; // Earth's gravitational constant times mass in m^3/s^2
};

#endif
