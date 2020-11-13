#include "collection.h"

Collection::Collection(const int l, const int w) { // ����������� �������������
    if (l > 0 && w > 0) {
        resistors_ = new Resistor *[l];
        for (int i = 0; i < l; i++) {
            resistors_[i] = new Resistor [w];
            }
        length_ = l;
        width_ = w;
        size_ = w * l;
    }
    else {
        cout << "Error: Incorrect values.\n";
    }
}

Collection::Collection(const Collection& c) { // ����������� �����������
    length_ = c.getLength();
    width_ = c.getWidth();
    size_ = c.getSize();
    resistors_ = c.resistors_;
}

void Collection::deleteCollection() { // �����, ��������� ��� �������� �������
    if(resistors_) {
        for (int i = 0; i < length_; i++) {
            delete [] resistors_[i];
            resistors_[i] = NULL;
        }
        delete [] resistors_;
    }
    length_ = 0;
    width_ = 0;
    size_ = 0;
}

const int& Collection::getLength() const { // ������ �����
    return length_;
}

const int& Collection::getWidth() const { // ������ ������
    return width_;
}

const int& Collection::getSize() const { // ������ ����� ���������� ��������
    return size_;
}

const Resistor& Collection::getResistor(const int& length, const int& width) const { // ����� ������� � �������� �� �������
    if ((0 <= length && length < length_) && (0 <= width && width < width_)) {
        return resistors_[length][width];
    }
    else {
        throw 1;
    }
}

void Collection::setResistor(const int length, const int width, const Resistor& resistor) { // ������ �������� ���������
    if (0 <= length && length < length_ && 0 <= width && width < width_) {
        resistors_[length][width] = resistor;
    }
    else {
        cout << "Error: Incorrect values.\n";
    }
}

bool Collection::operator == (const Collection& second) {
    if(length_ != second.getLength() && width_ != second.getWidth()) {
        return 0;
    }
    else {
        for (int i = 0; i < length_; i++) {
            for (int j = 0; j < width_; j++) {
                if(getResistor(i,j) != second.getResistor(i,j)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}
