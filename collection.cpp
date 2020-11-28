#include "collection.h"

Collection::Collection(const int& l, const int& w) { // конструктор инициализации
    if (l > 0 && w > 0) {
        resistors_ = new Resistor *[l];
        for (int i = 0; i < l; i++) {
            resistors_[i] = new Resistor [w];
        }
        length_ = l;
        width_ = w;
        size_ = w * l;
        current_freq_ = 1;
        current_source_ = NULL;
    }
    else {
        cout << "Error: Incorrect values.\n";
    }
}

Collection::Collection(const Collection& c) { // конструктор копирования
    length_ = c.getLength();
    width_ = c.getWidth();
    size_ = c.getSize();
    current_freq_ = c.getFreq();
    current_source_ = c.current_source_;
    resistors_ = c.resistors_;
}

void Collection::deleteCollection() { // метод, удаляющий все хранимые объекты
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

int Collection::getLength() const { // геттер длины
    return length_;
}

int Collection::getWidth() const { // геттер ширины
    return width_;
}

int Collection::getSize() const { // геттер числа хранящихся объектов
    return size_;
}

double Collection::getFreq() const { // геттер частоты тока
    return current_freq_;
}

double Collection::getSource(const int& length_pos) const { // геттер списка источников тока
    return current_source_[length_pos];
}

Resistor Collection::getResistor(const int& length_pos, const int& width_pos) const { // метод доступа к элементу по индексу
    if ((0 <= length_pos && length_pos < length_) && (0 <= width_pos && width_pos < width_)) {
        return resistors_[length_pos][width_pos];
    }
    else {
        throw 1;
    }
}

double Collection::getPotential(const int& i) const { // расчёт потенциала
    return (current_source_[i] - current_freq_) / resistors_[i % length_][i / width_].getResist();
}

void Collection::setFreq(const int& length, const int& width, const double& current_freq) { // сеттер частоты тока
    if (0 <= length && length < length_ && 0 <= width && width < width_) {
        if (current_freq <= 0) {
            current_freq_ = 1;
        }
        else {
            current_freq_ = current_freq;
        }
    }
    else {
        cout << "Error: Incorrect values.\n";
    }
}

void Collection::setSource(double *c) { // сеттер списка источников тока
    current_source_ = c;
}

void Collection::setResistor(const int& length, const int& width, const Resistor& resistor) { // сеттер элемента коллекции
    if (0 <= length && length < length_ && 0 <= width && width < width_) {
        resistors_[length][width] = resistor;
    }
    else {
        cout << "Error: Incorrect values.\n";
    }
}

void Collection::saveCollection(const string& file_name) const { // метод сохранения в файл
    ofstream file;
    file.open(file_name);
    file << getWidth() << "\n" << getLength() << "\n";
    for (int i = 0; i < getWidth(); i++){
        for (int j = 0; j < getLength(); j++){
                file << getResistor(i,j).getNumber() <<"\n";
                file << getResistor(i,j).getResist() <<"\n";
        }
    }
    file.close();
}

void Collection::loadCollection(const string& file_name) { // метод загрузки из файла
    int len, wid;
    double res;
    ifstream file;
    file.open(file_name);
    string str;
    Resistor** resistors_=NULL;
    if(!file) {
        cout << "File error";
    }
    else {
        file >> len >> wid;
        resistors_ = new Resistor *[len];
        for (int i = 0; i < len; i++) {
            resistors_[i] = new Resistor [wid];
            for (int j = 0; j < wid; j++) {
                file >> str >> res;
                setResistor(i, j, Resistor(str, res));
            }
        }
    }
}

bool Collection::operator == (const Collection& second) const {
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
