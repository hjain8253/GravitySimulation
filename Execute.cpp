#include "Execute.h"
#include <iostream>
#include <fstream>
#include <sstream>

Execute* Execute::mExecute = NULL;
Execute* Execute::getInstance() {
    if (mExecute == NULL) {
        mExecute = new Execute();
    }
    return mExecute;
}

Execute::Execute() : filename("EMG2008_coeff.txt") {}

void Execute::build() {
    int curr_n = -1;
    int n;
    int m;
    double Cnm, Snm;
    std::string line;
    std::ifstream myfile(filename);

    if (!myfile) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }
    Order* nOrder = nullptr;
    while (std::getline(myfile, line)) {
        std::replace(line.begin(), line.end(), 'D', 'E');
        std::istringstream iss(line);
        iss >> std::ws >> n >> std::ws >> m >> std::ws >> Cnm >> std::ws >> Snm;

        if (iss.fail()) {
            std::cerr << "Error reading data from line: " << line << std::endl;
            continue;
        }

  		if (n != curr_n) {
            nOrder = new Order(n);
            n_orders.push_back(nOrder);
            curr_n = n;
        }
        Degree* mDegree = new Degree(m, Cnm, Snm);
        nOrder->addDegree(mDegree);
    }
}

double Execute::calculatePotential(double r, double phi, double lambda) {
    double V = 0.0;
    Legendre aLegendre(n_orders.size()+1, std::sin(phi));

    for (const auto& order : n_orders) {
        int n = order->n;
        double termScaling = std::pow(R / r, n); 
        for (const auto& degree : order->m_degrees) {
            int m = degree->m;
            double Cnm = degree->Cnm;
            double Snm = degree->Snm;
            double Pnm = aLegendre.calculatePnm(n, m);
            double term = (Cnm * std::cos(m * lambda) + Snm * std::sin(m * lambda)) * Pnm;
            V += termScaling * term;
        }
    }
    V = - (GM / R) * V;
    return V;
}


void Execute::calculateAcceleration(double r, double phi, double lambda, double& ax, double& ay, double& az) {
    const double epsilon = 1e-6;
    double V = calculatePotential(r, phi, lambda);
	std:: cout << "The Gravitational Potential is: " << V << std::endl;
    double V_r = calculatePotential(r + epsilon, phi, lambda);
    double V_phi = calculatePotential(r, phi + epsilon, lambda);
    double V_lambda = calculatePotential(r, phi, lambda + epsilon);

    double dV_dr = (V - V_r) / epsilon;
    double dV_dphi = (V - V_phi) / epsilon;
    double dV_dlambda = (V - V_lambda) / epsilon;

    ax = -dV_dr;
    ay = -dV_dphi;
    az = -dV_dlambda;
}

void Execute::calculate(double r, double phi, double lambda) {
	double ax, ay, az;
	calculateAcceleration(r, phi, lambda, ax, ay, az);
	std::cout << " " << ax << " " << ay << " "  << az << " " << std::endl;
}
