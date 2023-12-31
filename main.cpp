#include "HashMap/hashMap.h"
#include "BinarySearchTree/BinarySearchTree.h"
#include "SingleLinkedList/SinglyLinkedList.h"
#include "DoubleLinkedList/DblLnkdList.h"
#include "Array/Array.h"


void hashTableTest(){
    //создадим хэш таблицу
    auto table = createHashMapTable();

    //вставим значения
    insertHashMap(table, "hello", 15);
    insertHashMap(table, "world", 16);
    insertHashMap(table, "test", 42);

    //перезапишем существующее значение
    insertHashMap(table, "hello", 19);

    //проверка на коллизию
    // Я В ХЭШ ФУНКЦИИ ВРУЧНУЮ ЗАДАЛ, ЧТОБЫ НА ТАКИЕ КЛЮЧИ ДАВАЛ ОДИНАКОВЫЙ ХЭШ!!!!
    insertHashMap(table, "testCollision", 57);
    insertHashMap(table, "testCollision2", 58);

    //удалим элемент по ключу world
    deleteHashMapItem(table,"world");

    //удалим элемент с коллизией
    deleteHashMapItem(table,"testCollision");

    //поиск элементов по ключу и их вывод
    std::cout << SearchHashMapItem(table, "hello") << std::endl;
    std::cout << SearchHashMapItem(table, "world") << std::endl;
    std::cout << SearchHashMapItem(table, "test") << std::endl;

    std::cout << SearchHashMapItem(table, "testCollision") << std::endl;
    std::cout << SearchHashMapItem(table, "testCollision2") << std::endl;

    std::cout<<"-----"<<std::endl;
}

void binarySearchTreeTest(){
    //создадим пустой head
    TreeNode* head = nullptr;

    //вставим в дерево значения
    insertTree(head,15);
    insertTree(head,20);
    insertTree(head,10);
    insertTree(head,5);
    insertTree(head,12);
    insertTree(head,25);

    PrintBT(head,0);

    //удалим значение 15
    removeTreeNodeByData(head,15);

    //найдем значения родителя у узла со значением 25
    std::cout << searchTree(head,25)->parent->data << std::endl;

    //найдем min и max элементы дерева
    std::cout << TreeMaxNode(head)->data << " ";
    std::cout << TreeMinNode(head)->data << std::endl;

    PrintBT(head,0);
}

void singlyListTest(){
    //пустой head
    SingleListNode* head = nullptr;

    //добавляем элементы в начало списка
    pushSingleList(head,3);
    pushSingleList(head,2);
    pushSingleList(head,1);
    pushSingleList(head,4);
    pushSingleList(head,5);
    printSingleList(head);
    std::cout << std::endl;

    //ищем указатель на элемент с датой 1
    SingleListNode* addressNode = searchSingleList(head,1);
    //для проверки выводим его значение
    std::cout << addressNode->data << std::endl;

    //вставляем 99 после элемента списка со значением 1
    addNodeByAddressSingleList(addressNode,99);
    //выводим список для проверки
    printSingleList(head);
    std::cout << std::endl;

    //достаем первый элемент из списка
    int myPopInt = popSingleList(head);
    //выводим дату взятого элемента
    std::cout << "we pop: " <<myPopInt << std::endl;
    //проверяем список
    printSingleList(head);
    std::cout << std::endl;

    //удалим добавленную 99
    addressNode = searchSingleList(head,1);
    deleteByAddressSingleList(addressNode);
    printSingleList(head);

    //отчистим список
    clearSingleList(head);
    std::cout << "new list: " << std::endl;
    printSingleList(head);

    std::cout<<"-----"<<std::endl;
}

void doubleLinkedListTest(){
    //создаем список
    DLList list = {0, nullptr, nullptr};

    //закидываем значения в конец
    enqueueDoubleList(list,15);
    enqueueDoubleList(list,30);
    enqueueDoubleList(list,45);
    enqueueDoubleList(list,55);
    //выводим список
    printDoubleList(list);
    std::cout << std::endl;

    //достаем последний элемент 2 раза и выводим его
    std::cout << dequeueDoubleList(list) << std::endl;
    std::cout << dequeueDoubleList(list) << std::endl;
    //выводим новый список
    printDoubleList(list);
    std::cout << std::endl;

    //очищаем список
    deleteDoubleList(list);
    //выводим новый список
    std::cout << "new list: " << std::endl;
    printDoubleList(list);

    std::cout<<"-----"<<std::endl;
}

void arrayTest(){
    Array arr{};
    initialize(arr, 5);

    push_back(arr, "1");
    push_back(arr, "5");
    push_back(arr, "10");
    printArray(arr);

    getByIndex(arr, 1);
    getByIndex(arr, 15);

    addIndex(arr, 2, "15");
    printArray(arr);

    deleteIndex(arr, 1);
    printArray(arr);

    search(arr, "10");
    search(arr, "50");
}

int main() {
    hashTableTest();

    binarySearchTreeTest();

    singlyListTest();

    doubleLinkedListTest();

    arrayTest();
}
