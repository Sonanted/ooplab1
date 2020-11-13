#ifndef COLLECTION_H
#define COLLECTION_H
#include "resistor.h"

class Collection
{
public:
    Collection(const int length_, const int width_);
    Collection(const Collection& collection);

    const Resistor& getResistor(const int& len, const int& wid) const;
    const int& getLength() const;
    const int& getWidth() const;
    const int& getSize() const;

    void setResistor(const int length, const int width, const Resistor& resistor);
    void deleteCollection();

    bool operator == (const Collection& second);
private:
    Resistor **resistors_;
    int width_;
    int length_;
    int size_;
};

#endif // COLLECTION_H

// ����������� �������������
// ����������� �����������
// ����� ������� � �������� �� �������
// ����� ��������� ��� �������� �������
// ����� ������������ ����� ���������� ��������
// ����� ��� ������ � ����
// ����� ��� �������� �� �����
// ������� �������� ���� ��������� �� ��������� (�����������)
// ������� ����������������� � ���������������� ������ ��������� ��������� �� �����
