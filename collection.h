#ifndef COLLECTION_H
#define COLLECTION_H
#include "resistor.h"
#include <iostream>
#include <fstream>

class Collection
{
public:
    Collection();
    Collection(const int& l, const int& w); // ����������� �������������
    Collection(const Collection& c); // ����������� �����������

    Resistor getResistor(const int& length_pos, const int& width_pos) const; // ����� ������� � �������� �� �������
    int getRows() const;
    int getCols() const;
    int getSize() const; // ������ ����� ���������� ��������
    double getFreq() const; // ������ ������� ����
    double getPotential(const int& number) const; // ������ ����������

    void setResistor(const int& length_pos, const int& width_pos, const Resistor& resistor); // ������ �������� ���������
    void setFreq(const double& current_freq); // ������ ������� ����
    void deleteCollection(); // �����, ��������� ��� �������� �������
    void saveCollection(const string& file_name) const; // ����� ���������� � ����
    void loadCollection(const string& file_name); // ����� �������� �� �����

    bool operator == (const Collection& second) const;
    Resistor* operator [] (const int i);
private:
    Resistor **resistors_;
    double current_freq_;
    int cols_, rows_, size_;
};

#endif // COLLECTION_H
