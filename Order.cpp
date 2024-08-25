#include "Order.h"

Order::Order(int n_val) : n(n_val) {}

void Order::addDegree(Degree* aDegree) {
    m_degrees.push_back(aDegree);
}
