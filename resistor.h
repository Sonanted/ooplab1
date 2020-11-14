#ifndef RESISTOR_H
#define RESISTOR_H

#include <iostream>
#include <string>

using namespace std;

class Resistor
{
public:
    Resistor();
    Resistor(const string& number,double resist);
    Resistor(const Resistor& r);

    string getNumber() const;
    double getResist() const;

    void setNumber(const string& number);
    void setResist(const double& resist);

    bool operator != (const Resistor& second) const;

private:

    string number_;
    double resist_;
};



#endif // RESISTOR_H
