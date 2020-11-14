#include "collection.h"

Collection::Collection(const int& l, const int& w) { // ����������� �������������
    if (l > 0 && w > 0) {
        resistors_ = new Resistor *[l];
        for (int i = 0; i < l; i++) {
            resistors_[i] = new Resistor [w];
        }
        length_ = l;
        width_ = w;
        size_ = w * l;
        current_freq_ = 0;
        current_source_ = NULL;
    }
    else {
        cout << "Error: Incorrect values.\n";
    }
}

Collection::Collection(const Collection& c) { // ����������� �����������
    length_ = c.getLength();
    width_ = c.getWidth();
    size_ = c.getSize();
    current_freq_ = c.getCurrentFreq();
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
    current_freq_ = 0;
    current_source_ = NULL;
}

int Collection::getLength() const { // ������ �����
    return length_;
}

int Collection::getWidth() const { // ������ ������
    return width_;
}

int Collection::getSize() const { // ������ ����� ���������� ��������
    return size_;
}

double Collection::getCurrentFreq() const { // ������ ������� ����
    return current_freq_;
}

double Collection::getCurrentSource(const int& length_pos) const { // ������ ������ ���������� ����
    return current_source_[length_pos];
}

Resistor Collection::getResistor(const int& length_pos, const int& width_pos) const { // ����� ������� � �������� �� �������
    if ((0 <= length_pos && length_pos < length_) && (0 <= width_pos && width_pos < width_)) {
        return resistors_[length_pos][width_pos];
    }
    else {
        throw 1;
    }
}

double Collection::getPotential(const int& i) const { // ������ ����������
    return (current_source_[i] - current_freq_) / resistors_[i % length_][i / width_].getResist();
}

void Collection::setCurrentFreq(const int& length, const int& width, const double& current_freq) { // ������ ������� ����
    if (0 <= length && length < length_ && 0 <= width && width < width_) {
        current_freq_ = current_freq;
    }
    else {
        cout << "Error: Incorrect values.\n";
    }
}

void Collection::setCurrentSource(double *c) { // ������ ������ ���������� ����
    current_source_ = c;
}

void Collection::setResistor(const int& length, const int& width, const Resistor& resistor) { // ������ �������� ���������
    if (0 <= length && length < length_ && 0 <= width && width < width_) {
        resistors_[length][width] = resistor;
    }
    else {
        cout << "Error: Incorrect values.\n";
    }
}

void Collection::saveCollection(const Collection& c, const string& file_name) const { // ����� ���������� � ����
    ofstream file;
    file.open(file_name);
    file << c.getWidth() << "\n" << c.getLength() << "\n";
    for (int i = 0; i < c.getWidth();i++){
        for (int j = 0; j < c.getLength(); j++){
                file << c.getResistor(i,j).getNumber() <<"\n";
                file << c.getResistor(i,j).getResist() <<"\n";
        }
    }
    file.close();
}

void Collection::loadCollection(const string& file_name) { // ����� �������� �� �����
    int len, wid;
    ifstream file;
    file.open(file_name);
    std::string str;
    Resistor** resistors=NULL;
    if(!file) {
        cout << "File error";
    }
    else {
        file >> len >> wid;
        resistors = new Resistor *[len];
        for (int i = 0; i < len; i++) {
            resistors[i] = new Resistor [wid];
            for (int j = 0; j < wid; j++) {
                file >> str;
            setResistor(i, j, Resistor());
            }
        }
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
