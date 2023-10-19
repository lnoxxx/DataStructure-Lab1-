#pragma once
#include <iostream>

struct array{
    int* array;
    int size;
};

array* createArray();
void printArray(array* arr);
void addChangeByIndex(array* arr, const int& index, const int& data);
void removeByIndex (array* arr,const int& index);