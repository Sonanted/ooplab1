#include "inductance.h"

Inductance::Inductance() :
    Resistor() {}

Inductance::Inductance(const string& number, const double& resist) :
    Resistor(number, resist) {}

Inductance::Inductance(const Inductance& other) :
    Resistor(other) {}

void Inductance::setCapacity(const double& capacity) {
    if (capacity <= 0) {
        cout << "Capacity can't be less than or equal to 0.\n Capacity set to 1";
        capacity_ = 1;
    }
    else {
      capacity_ = capacity;
    }
}

double Inductance::getCapacity() const {
    return capacity_;
}

double Inductance::calculateFreq(const double& freq) {
    return sqrt(getResist() * getResist() + (1 / ((capacity_ * freq) * (capacity_ * freq))));
}
