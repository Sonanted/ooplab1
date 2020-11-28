#ifndef COLLECTION_H
#define COLLECTION_H
#include "resistor.h"
#include <iostream>
#include <fstream>

class Collection
{
public:
    Collection(const int& l, const int& w); // ����������� �������������
    Collection(const Collection& c); // ����������� �����������

    Resistor getResistor(const int& length_pos, const int& width_pos) const; // ����� ������� � �������� �� �������
    int getLength() const;
    int getWidth() const;
    int getSize() const; // ������ ����� ���������� ��������
    double getFreq() const; // ������ ������� ����
    double getSource(const int& len) const; // ������ ������ ���������� ����
    double getPotential(const int& number) const; // ������ ����������

    void setResistor(const int& length_pos, const int& width_pos, const Resistor& resistor); // ������ �������� ���������
    void setFreq(const int& length, const int& width, const double& current_freq); // ������ ������� ����
    void setSource(double *c); // ������ ������ ���������� ����
    void deleteCollection(); // �����, ��������� ��� �������� �������
    void saveCollection(const string& file_name) const; // ����� ���������� � ����
    void loadCollection(const string& file_name); // ����� �������� �� �����

    bool operator == (const Collection& second) const;
private:
    Resistor **resistors_;
    double *current_source_, current_freq_;
    int width_, length_, size_;
};

#endif // COLLECTION_H
