#ifndef INDUCTANCE_H
#define INDUCTANCE_H
#include "resistor.h"
#include <cmath>

class Inductance : public Resistor
{
public:
    Inductance();
    Inductance(const string& number, const double& resist);
    Inductance(const Inductance& other);

    double getCapacity() const;

    void setCapacity(const double& capacity);
    double calculateFreq(const double& freq);

private:
    double capacity_;
};

#endif // INDUCTANCE_H
