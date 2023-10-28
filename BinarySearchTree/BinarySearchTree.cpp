#include "BinarySearchTree.h"

//функция вставки от О(log n) до O(n) зависит от балансировки
void insertTree (TreeNode*& head, int data){

    //создаем новый узел
    auto* newNode = new TreeNode;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->data = data;

    //если дерево пустое
    if (head == nullptr){
        newNode->parent = nullptr;
        head = newNode;
        return;
    }

    TreeNode* currentNode = head;
    //поиск места для вставки
    while (currentNode != nullptr){
        //если значение больше узла
        if (data > currentNode->data)
            //если правый наследник пустой не пустой, идем туда
            if (currentNode->right != nullptr) {
                currentNode = currentNode->right;
                continue;
            }
            //если пустой, вставляем
            else {
                newNode->parent = currentNode;
                currentNode->right = newNode;
                return;
            }
        //если значение меньше узла
        else if (data < currentNode->data) {
            //если не пустой, идем туда
            if (currentNode->left != nullptr) {
                currentNode = currentNode->left;
                continue;
            }
            //если пустой, вставляем
            else {
                newNode->parent = currentNode;
                currentNode->left = newNode;
                return;
            }
        }
        // если узел уже существует, ниче не делаем
        else if (data == currentNode->data) {
            std::cout << "There is already a node" << std::endl;
            return;
        }
    }
}

//функция поиска от О(log n) до O(n) зависит от балансировки
TreeNode* searchTree (TreeNode* head, int data){
    //пока не упремся в листья
    while (head != nullptr){
        //если искомое значение больше, идем вправо, иначе в лево
        if (data > head->data){
            head = head->right;
            continue;
        }
        else if (data < head->data){
            head = head->left;
            continue;
        }
        //если равен, возвращаем его
        else return head;
    }
    //если не нашли, nullptr
    return nullptr;
}

//функция поиска максимального элемента от О(log n) до O(n) зависит от балансировки
TreeNode* TreeMaxNode(TreeNode* head){
    //идем до упора вправо
    while (head->right != nullptr){
        head = head->right;
    }
    return head;
}

//функция поиска минимального элемента от О(log n) до O(n) зависит от балансировки
TreeNode* TreeMinNode(TreeNode* head){
    //идем до упора влево
    while (head->left != nullptr){
        head = head->left;
    }
    return head;
}

//функция удаления узла по указателю от О(1) до O(n) зависит от кол-ва потомков и балансировки
void removeTreeNode(TreeNode*& deletedNode){
    //если у узла 2 потомка
    if (deletedNode->left != nullptr && deletedNode->right != nullptr){
        TreeNode* leftMax = TreeMaxNode(deletedNode->left);
        deletedNode->data = leftMax->data;
        removeTreeNode(leftMax);
        return;
    }
    //если у узла 1 левый потомок
    else if (deletedNode->left != nullptr){
        if (deletedNode == deletedNode->parent->left){
            deletedNode->parent->left = deletedNode->left;
        } else{
            deletedNode->parent->right = deletedNode->left;
        }
    }
    //если у узла 1 правый потомок
    else if (deletedNode->right != nullptr){
        if (deletedNode == deletedNode->parent->left){
            deletedNode->parent->left = deletedNode->right;
        } else{
            deletedNode->parent->right = deletedNode->right;
        }
    }
    //если у узла нет потомков
    else {
        if (deletedNode == deletedNode->parent->left){
            deletedNode->parent->left = nullptr;
        } else{
            deletedNode->parent->right = nullptr;
        }
    }
    delete deletedNode;
}

//то же удаление, только по значению
void removeTreeNodeByData(TreeNode* head, int data){
    //ищем, удаляем
    TreeNode* deletedNode = searchTree(head,data);
    removeTreeNode(deletedNode);
}

void PrintBT(TreeNode* head, int depth) {
    if (head == nullptr){
        return;
    }
    PrintBT(head->right, depth + 1);
    for (int i = 0; i < depth; i++) {
        std::cout << "   ";
    }
    std::cout << head->data << std::endl;
    PrintBT(head->left, depth + 1);
}