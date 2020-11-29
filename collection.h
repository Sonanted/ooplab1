#ifndef COLLECTION_H
#define COLLECTION_H
#include "resistor.h"
#include <iostream>
#include <fstream>

class Collection
{
public:
    Collection();
    Collection(const int& l, const int& w); // конструктор инициализации
    Collection(const Collection& c); // конструктор копирования

    Resistor getResistor(const int& length_pos, const int& width_pos) const; // метод доступа к элементу по индексу
    int getRows() const;
    int getCols() const;
    int getSize() const; // геттер числа хранящихся объектов
    double getFreq() const; // геттер частоты тока
    double getPotential(const int& number) const; // расчёт потенциала

    void setResistor(const int& length_pos, const int& width_pos, const Resistor& resistor); // сеттер элемента коллекции
    void setFreq(const double& current_freq); // сеттер частоты тока
    void deleteCollection(); // метод, удаляющий все хранимые объекты
    void saveCollection(const string& file_name) const; // метод сохранения в файл
    void loadCollection(const string& file_name); // метод загрузки из файла

    bool operator == (const Collection& second) const;
    Resistor* operator [] (const int i);
private:
    Resistor **resistors_;
    double current_freq_;
    int cols_, rows_, size_;
};

#endif // COLLECTION_H
