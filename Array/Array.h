#pragma once
#include <iostream>

struct Array{
    std::string* array;
    int size;
    int capacity;
};

void initialize(Array& list, int initialCapacity);
void push_back(Array& list, const std::string& value);
void addIndex(Array& list, int index, const std::string& value);
void deleteIndex(Array& list, int index);
void search(const Array& list, const std::string& value);
void getByIndex(const Array& list, const int index);
void printArray(const Array& list);