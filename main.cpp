#include <iostream>
#include <assert.h>
#include "resistor.h"
#include "collection.h"

using namespace std;

void resistorEmptyConstructor() { // тест пустого конструктора
    Resistor resistor;
    assert(resistor.getNumber() == "");
    assert(resistor.getResist() == 0);
}

void resistorInitializationConstructor() { // тест конструктора инициализации
    Resistor resistor1("ABC", 123);
    assert(resistor1.getNumber() == "ABC");
    assert(resistor1.getResist() == 123);
    Resistor resistor2("30F", -2);
    assert(resistor2.getNumber() == "30F");
    assert(resistor2.getResist() == 0);
}

void resistorCopyConstructor() { // тест конструктора копирования
    Resistor resistor1("10A", 11);
    Resistor resistor2(resistor1);
    assert(resistor2.getNumber() == "10A");
    assert(resistor1.getResist() == 11);
}

void resistorGetNumber() { // тест геттера номера
    Resistor resistor("13M", 3);
    assert(resistor.getNumber() == "13M");
}

void resistorGetResist() { // тест геттера сопротивления
    Resistor resistor("111", 222);
    assert(resistor.getResist() == 222);
}

void resistorSetNumber() { // тест сеттера номера
    Resistor resistor;
    resistor.setNumber("2B");
    assert(resistor.getNumber() == "2B");
}

void resistorSetResist() { // тест сеттера сопротивления
    Resistor resistor;
    resistor.setResist(40);
    assert(resistor.getResist() == 40);
    resistor.setResist(-40);
    assert(resistor.getResist() == 0);
}

void allResistorTests() { // вызов всех тестов
    resistorEmptyConstructor();
    cout << "Empty constructor is OK\n";
    resistorInitializationConstructor();
    cout << "Initialization constructor is OK\n";
    resistorCopyConstructor();
    cout << "Copy constructor is OK\n";
    resistorGetNumber();
    cout << "GetNumber method is OK\n";
    resistorGetResist();
    cout << "GetResist method is OK\n";
    resistorSetNumber();
    cout << "SetNumber method is OK\n";
    resistorSetResist();
    cout <<"SetResist method is OK\n";
}

void collectionIntializationConstructor() { // тест конструктора инициализации коллекции
    Collection collection(4, 5);
    assert(collection.getSize() == 4 * 5);
}

void collectionCopyConstructor() {
    Collection collection(2, 2);
    Collection collection2{collection};
    Resistor r("1",1);
    collection2.setResistor(1, 1, r);
    if (collection == collection2) {
        cout << "Copy constructor collection is OK";
    }
}

void collectionDestructor() {
    Collection collection(3, 2);
    collection.deleteCollection();
    cout << collection.getSize() << '\n';
    cout << collection.getWidth() << '\n';
    cout << collection.getLength() << '\n';
}

void collectionReadAndWriteToFile() {

}

void compareCollections() {

}

void collectionPrint() {

}

int main()
{
    Collection collection(2, 2);
    Collection collection2{collection};
    Resistor r("1",1);
    Resistor rr("2",2);
    if (r != rr) {
        cout << "no";
    }
    else {
        cout << "yes";
    }
    collection2.setResistor(1, 1, r);
    if (collection == collection2) {
        cout << "Copy constructor collection is OK";
    }
}
