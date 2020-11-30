#include "collection.h"

Collection::Collection() {}

Collection::Collection(const int& rows, const int& cols) { // конструктор инициализации
    if (rows > 0 && cols > 0) {
        resistors_ = new Resistor *[rows];
        for (int i = 0; i < rows; i++) {
            resistors_[i] = new Resistor [cols];
        }
        rows_ = rows;
        cols_ = cols;
        size_ = cols * rows;
        current_freq_ = 1;
    }
    else {
        cout << "Error: Incorrect values.\n";
    }
}

Collection::Collection(const Collection& c) { // конструктор копирования
    rows_ = c.getRows();
    cols_ = c.getCols();
    size_ = c.getSize();
    current_freq_ = c.getFreq();
    resistors_ = c.resistors_;
}

void Collection::deleteCollection() { // метод, удаляющий все хранимые объекты
    if(resistors_) {
        for (int i = 0; i < rows_; i++) {
            delete [] resistors_[i];
            resistors_[i] = NULL;
        }
        delete [] resistors_;
    }
    rows_ = 0;
    cols_ = 0;
    size_ = 0;
    current_freq_ = 0;
}

int Collection::getRows() const { // геттер длины
    return rows_;
}

int Collection::getCols() const { // геттер ширины
    return cols_;
}

int Collection::getSize() const { // геттер числа хранящихся объектов
    return size_;
}

double Collection::getFreq() const { // геттер частоты тока
    return current_freq_;
}

Resistor Collection::getResistor(const int& rows_pos, const int& cols_pos) const { // метод доступа к элементу по индексу
    if ((0 <= rows_pos && rows_pos < rows_) && (0 <= cols_pos && cols_pos < cols_)) {
        return resistors_[rows_pos][cols_pos];
    }
    else {
        throw 1;
    }
}

double Collection::getPotential(const int& i) const { // расчёт потенциала

    return current_freq_ / resistors_[i / (cols_)][i % (cols_)].getResist();
}

void Collection::setFreq(const double& current_freq) { // сеттер частоты тока
    if (current_freq <= 0) {
        current_freq_ = 1;
    }
    else {
        current_freq_ = current_freq;
    }
}

void Collection::setResistor(const int& length, const int& width, const Resistor& resistor) { // сеттер элемента коллекции
    //if (0 <= length && length < rows_ && 0 <= width && width < cols_) {
        resistors_[length][width] = resistor;
    //}
    //else {
     //   cout << "Error: Incorrect values.\n";
    //}
}

void Collection::saveCollection(const string& file_name) const { // метод сохранения в файл
    ofstream file;
    file.open(file_name);
    file << getFreq() << "\n";
    file << getCols() << "\n" << getRows() << "\n";
    for (int i = 0; i < getRows(); i++){
        for (int j = 0; j < getCols(); j++){
                file << getResistor(i,j).getNumber() <<"\n";
                file << getResistor(i,j).getResist() <<"\n";
        }
    }
    file.close();
}

void Collection::loadCollection(const string& file_name) { // метод загрузки из файла
    int rows, cols;
    double res, freq;
    ifstream file;
    file.open(file_name);
    string str;
    Resistor** resistors_;
    if(!file) {
        cout << "File error";
    }
    else {
        file >> freq >> rows >> cols;
        current_freq_ = freq;
        rows_ = rows;
        cols_ = cols;
        resistors_ = new Resistor *[rows];
        for (int i = 0; i < rows; i++) {
            resistors_[i] = new Resistor [cols];
            for (int j = 0; j < cols; j++) {
                file >> str >> res;
                const double ress = res;
                Resistor temp(str, ress);
                setResistor(i, j, temp);
            }
        }
    }
}

bool Collection::operator == (const Collection& second) const {
    if(rows_ != second.getRows() && cols_ != second.getCols()) {
        return 0;
    }
    else {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                if(getResistor(i,j) != second.getResistor(i,j)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

Resistor* Collection::operator[](const int i) {
    return resistors_[i];
}
