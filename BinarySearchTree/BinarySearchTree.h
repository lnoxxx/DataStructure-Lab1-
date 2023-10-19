#pragma once
#include <iostream>

// Структура узла дерева
struct TreeNode{
    //значение(ключ)
    int data;
    //левый потомок
    TreeNode* left;
    //правый потомок
    TreeNode* right;
    //родитель
    TreeNode* parent;
};

void insertTree (TreeNode*& head, int data);
TreeNode* searchTree (TreeNode* head, int data);
TreeNode* TreeMaxNode(TreeNode* head);
TreeNode* TreeMinNode(TreeNode* head);
void removeTreeNode(TreeNode*& deletedNode);
void removeTreeNodeByData(TreeNode* head, int data);
