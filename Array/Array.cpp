#include "Array.h"

//функция создания массива
array* createArray(){
    auto* arr = new array;
    arr->array = new int[5];
    arr->size = 5;
    for (int k = 0; k<arr->size;k++){
        arr->array[k] = 0;
    }
    return arr;
}

//функция вывода массива
void printArray(array* arr){
    for (int k = 0; k<arr->size;k++){
        std::cout << arr->array[k] << " ";
    }
    std::cout << std::endl;
}

//изменение элемента - O(1)
//добавление нового элемента O(n) (если не считать заполнение нулями)
void addChangeByIndex(array* arr, const int& index, const int& data){
    if (index < 0) return;
    if(arr->size <= index){
        int* newArr = new int[index+1];
        for (int k = 0; k<index+1;k++){
            newArr[k] = 0;
        }
        for (int k = 0; k<arr->size;k++){
            newArr[k] = arr->array[k];
        }
        newArr[index] = data;
        delete[] arr->array;
        arr->array = newArr;
        arr->size = index+1;
    }else{
        arr->array[index] = data;
    }
}

//удаление O(n-1)
void removeByIndex (array* arr,const int& index){
    if (index >= arr->size || index < 0) return;
    int* newArr = new int[arr->size-1];
    for (int k = 0; k<index;k++){
        newArr[k] = arr->array[k];
    }
    for (int k=index+1;k<arr->size;k++){
        newArr[k-1] = arr->array[k];
    }
    delete[] arr->array;
    arr->array = newArr;
    arr->size--;
}


