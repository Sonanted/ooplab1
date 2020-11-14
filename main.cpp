#include <iostream>
#include <assert.h>
#include "resistor.h"
#include "collection.h"

using namespace std;

void resistorEmptyConstructor() { // тест пустого конструктора класса
    Resistor resistor;
    assert(resistor.getNumber() == "");
    assert(resistor.getResist() == 0);
}

void resistorInitializationConstructor() { // тест конструктора инициализации класса
    Resistor resistor1("ABC", 123);
    assert(resistor1.getNumber() == "ABC");
    assert(resistor1.getResist() == 123);
    Resistor resistor2("30F", -2);
    assert(resistor2.getNumber() == "30F");
    assert(resistor2.getResist() == 0);
}

void resistorCopyConstructor() { // тест конструктора копирования класса
    Resistor resistor1("10A", 11);
    Resistor resistor2(resistor1);
    assert(resistor2.getNumber() == "10A");
    assert(resistor1.getResist() == 11);
}

void resistorGetNumber() { // тест геттера номера класса
    Resistor resistor("13M", 3);
    assert(resistor.getNumber() == "13M");
}

void resistorGetResist() { // тест геттера сопротивления класса
    Resistor resistor("111", 222);
    assert(resistor.getResist() == 222);
}

void resistorSetNumber() { // тест сеттера номера класса
    Resistor resistor;
    resistor.setNumber("2B");
    assert(resistor.getNumber() == "2B");
}

void resistorSetResist() { // тест сеттера сопротивления класса
    Resistor resistor;
    resistor.setResist(40);
    assert(resistor.getResist() == 40);
    resistor.setResist(-40);
    assert(resistor.getResist() == 0);
}

void allResistorTests() { // вызов всех тестов класса
    resistorEmptyConstructor();
    cout << "Resistor Empty constructor is OK\n";
    resistorInitializationConstructor();
    cout << "Resistor Initialization constructor is OK\n";
    resistorCopyConstructor();
    cout << "Resistor Copy constructor is OK\n";
    resistorGetNumber();
    cout << "Resistor GetNumber method is OK\n";
    resistorGetResist();
    cout << "Resistor GetResist method is OK\n";
    resistorSetNumber();
    cout << "Resistor SetNumber method is OK\n";
    resistorSetResist();
    cout <<"Resistor SetResist method is OK\n";
    cout <<"Resistor class is OK\n";
}

void collectionIntializationConstructor() { // тест конструктора инициализации коллекции
    Collection collection(4, 5);
    assert(collection.getSize() == 4 * 5);
}

void collectionCopyConstructor() { // тест конструктора копирования коллекции
    Collection collection(2, 2);
    Collection collection2{collection};
    assert(collection == collection2);
}

void collectionDestructor() {
    Collection collection(3, 2);
    collection.deleteCollection();
    assert(collection.getSize() == 0);
    assert(collection.getWidth() == 0);
    assert(collection.getLength() == 0);
}

void collectionReadAndWriteToFile() {
    Collection c(2,2), c2(2,2);
    Resistor r1("1",1.1), r2("2", 2.2), r3("z", 3.3), r4("4", 4.4);
    c.setResistor(0,0, r1);
    c.setResistor(0,1, r2);
    c.setResistor(1,0, r3);
    c.setResistor(1,1, r4);
    c.saveCollection("ye.txt");
    c2.loadCollection("ye.txt");
    assert(c.getResistor(1,1).getResist() == c2.getResistor(1,1).getResist());
}

void allCollectionTests() {
    collectionIntializationConstructor();
    cout << "Collection initialization constructor is OK\n";
    collectionCopyConstructor();
    cout << "Collection copy constructor is OK\n";
    collectionDestructor();
    cout << "Collection destructor is OK\n";
    collectionReadAndWriteToFile();
    cout << "Collection read and write to file methods is OK\n";
    cout << "Collection class is OK\n";
}

void printCollection(const Collection& c) {
    for (int i = 0; i < c.getLength(); i++) {
        for (int j = 0; j < c.getWidth(); j++) {
            cout << "resistor(" << i << ", " << j << "):\n";
            cout << "number: " << c.getResistor(i,j).getNumber() << "\n";
            cout << "resist: " << c.getResistor(i,j).getResist() << "\n\n";
        }
    }
}

int main()
{
    allResistorTests();
    allCollectionTests();
    Collection c(2, 2), c2(2, 2);
    Resistor r1("1",1.1), r2("2", 2.2), r3("z", 3.3), r4("4", 4.4);
    c.setResistor(0,0, r1);
    c.setResistor(0,1, r2);
    c.setResistor(1,0, r3);
    c.setResistor(1,1, r4);
    printCollection(c); // поэлементный вывод на экран

}
