#include "Array.h"

//инициализация
void initialize(Array& list, int initialCapacity) {
    list.capacity = initialCapacity;
    list.size = 0;
    list.array = new std::string[list.capacity];
}

//пуш бек
void push_back(Array& list, const std::string& value) {
    if (list.size == list.capacity) {
        int newCapacity = list.capacity + 5;
        auto* newArray = new std::string[newCapacity];
        for (int i = 0; i < list.size; i++) {
            newArray[i] = list.array[i];
        }
        delete[] list.array;
        list.array = newArray;
        list.capacity = newCapacity;
    }
    list.array[list.size] = value;
    list.size++;
}

void addIndex(Array& list, int index, const std::string& value) {
    if (index < 0 || index > list.size) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    if (list.size == list.capacity) {
        int newCapacity = list.capacity * 2;
        auto* newArray = new std::string[newCapacity];

        for (int i = 0; i < list.size; i++) {
            newArray[i] = list.array[i];
        }

        delete[] list.array;
        list.array = newArray;
        list.capacity = newCapacity;
    }
    for (int i = list.size; i > index; i--) {
        list.array[i] = list.array[i - 1];
    }
    list.array[index] = value;
    list.size++;
}

void deleteIndex(Array& list, int index) {
    if (index < 0 || index >= list.size) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    if (index == list.size){
        list.size--;
    }
    for (int i = index; i < list.size - 1; i++) {
        list.array[i] = list.array[i + 1];
    }
    list.size--;
}

void search(const Array& list, const std::string& value) {
    for (int i = 0; i < list.size; i++) {
        if (list.array[i] == value) {
            std::cout << "find" << std::endl;
            return;
        }
    }
    std::cout << "dont find" << std::endl;
}

void getByIndex(const Array& list, const int index) {
    if (index>=0 && index<=list.size) {
        std::cout << list.array[index] << std::endl;
    }
    else {
        std::cout <<"No such element" << std::endl;
    }
}

void printArray(const Array& list) {
    for (int i = 0; i < list.size; i++) {
        std::cout << list.array[i] << " ";
    }
    std::cout << std::endl;
}
