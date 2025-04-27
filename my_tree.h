#ifndef TREE_H
#define TREE_H

#include <string>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val);
};

Node* buildTree(const int* values, int size);
void printTree(Node* root, std::string prefix = "", bool isLeft = true);
void deleteTree(Node* root);

#endif
