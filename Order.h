#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "Degree.h"

// Order class represents an n holding a vector of m (degrees from 0 to n).

class Order {
public:
    int n;
    std::vector<Degree*> m_degrees;

    Order(int n_val);
    void addDegree(Degree* aDegree);
};

#endif
