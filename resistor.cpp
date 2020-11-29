#include "resistor.h"


Resistor::Resistor() { // конструктор по умолчанию
    number_ = "";
    resist_ = 1;
}

Resistor::Resistor(const string& number,const double& resist) { // конструктор инициализации
    number_ = number;
    if (resist <= 0) {
        cout << "Error: Incorrect value, resist value set to 1.\n";
        resist_ = 1;
    }
    else {
        resist_ = resist;
    }
}

Resistor::Resistor(const Resistor& r) { // конструктор копирования
    number_ = r.getNumber();
    resist_ = r.getResist();
}

string Resistor::getNumber() const { // геттер номера
    return number_;
}

double Resistor::getResist() const{ // геттер сопротивления
    return resist_;
}

void Resistor::setNumber(const string &number) { // сеттер номера
    number_ = number;
}

void Resistor::setResist(const double &resist) { // сеттер сопротивления
    if (resist <= 0) {
        cout << "Error: Incorrect value, resist value set to 1.\n";
        resist_ = 1;
    }
    else {
        resist_ = resist;
    }
}

bool Resistor::operator != (const Resistor& second) const {
    return((number_ != second.getNumber()) || (resist_ != second.getResist()));
}
