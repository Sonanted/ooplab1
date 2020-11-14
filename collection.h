#ifndef COLLECTION_H
#define COLLECTION_H
#include "resistor.h"
#include <iostream>
#include <fstream>

class Collection
{
public:
    Collection(const int& l, const int& w); // конструктор инициализации
    Collection(const Collection& c); // конструктор копирования

    Resistor getResistor(const int& length_pos, const int& width_pos) const; // метод доступа к элементу по индексу
    int getLength() const;
    int getWidth() const;
    int getSize() const; // геттер числа хранящихся объектов
    double getCurrentFreq() const; // геттер частоты тока
    double getCurrentSource(const int& len) const; // геттер списка источников тока
    double getPotential(const int& number) const; // расчёт потенциала

    void setResistor(const int& length_pos, const int& width_pos, const Resistor& resistor); // сеттер элемента коллекции
    void setCurrentFreq(const int& length, const int& width, const double& current_freq); // сеттер частоты тока
    void setCurrentSource(double *c); // сеттер списка источников тока
    void deleteCollection(); // метод, удаляющий все хранимые объекты
    void saveCollection(const string& file_name) const; // метод сохранения в файл
    void loadCollection(const string& file_name); // метод загрузки из файла

    bool operator == (const Collection& second) const;
private:
    Resistor **resistors_;
    double *current_source_, current_freq_;
    int width_, length_, size_;
};

#endif // COLLECTION_H
