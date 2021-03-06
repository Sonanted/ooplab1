#include "resistor.h"


Resistor::Resistor() { // ����������� �� ���������
    number_ = "";
    resist_ = 1;
}

Resistor::Resistor(const string& number,const double& resist) { // ����������� �������������
    number_ = number;
    if (resist <= 0) {
        cout << "Resist can't be less than or equal to 0. ";
        cout << "Resist value set to 1.\n";
        resist_ = 1;
    }
    else {
        resist_ = resist;
    }
}

Resistor::Resistor(const Resistor& r) { // ����������� �����������
    number_ = r.getNumber();
    resist_ = r.getResist();
}

string Resistor::getNumber() const { // ������ ������
    return number_;
}

double Resistor::getResist() const{ // ������ �������������
    return resist_;
}

void Resistor::setNumber(const string &number) { // ������ ������
    number_ = number;
}

void Resistor::setResist(const double &resist) { // ������ �������������
    if (resist <= 0) {
        cout << "Error: Resist can't be less than or equal to 0. ";
        cout << "Resist value set to 1.\n";
        resist_ = 1;
    }
    else {
        resist_ = resist;
    }
}

bool Resistor::operator != (const Resistor& second) const {
    return((number_ != second.getNumber()) || (resist_ != second.getResist()));
}

void Resistor::setCapacity(const double &capacity) {
    cout << "Error. There is no capacity assignment in this type of object";
}
