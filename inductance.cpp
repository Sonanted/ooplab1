#include "inductance.h"

Inductance::Inductance() :
    Resistor() {
    capacity_ = 1;
}

Inductance::Inductance(const string& number, const double& resist, const double& capacity) :
    Resistor(number, resist) {
    if (capacity <= 0) {
        cout << "Capacity can't be less than or equal to 0. ";
        cout << "Capacity set to 1\n";
        capacity_ = 1;
    }
    else {
        capacity_ = capacity;
    }

}

Inductance::Inductance(const Inductance& other) :
    Resistor(other) {
    capacity_ = other.getCapacity();
}

void Inductance::setCapacity(const double& capacity) {
    if (capacity <= 0) {
        cout << "Capacity can't be less than or equal to 0. ";
        cout << "Capacity set to 1\n";
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
