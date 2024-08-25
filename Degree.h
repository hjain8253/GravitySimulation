#ifndef DEGREE_H
#define DEGREE_H


// Degree Class holds the Cnm, Snm values for all n,m pairs. 

class Degree {
public:
    int m;
    double Cnm;
    double Snm;

    Degree(int m_val, double Cnm_val, double Snm_val);
};

#endif
