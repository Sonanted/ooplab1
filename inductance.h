#ifndef INDUCTANCE_H
#define INDUCTANCE_H
#include "resistor.h"
#include <cmath>

class Inductance : public Resistor
{
public:
    Inductance();
    Inductance(const string& number, const double& resist, const double& capacity_);
    Inductance(const Inductance& other);

    double getCapacity() const;
    virtual void setCapacity(const double& capacity) override;
    double calculateFreq(const double& freq);

private:
    double capacity_;
};

#endif // INDUCTANCE_H
