#include "my_tree.h"
#include <iostream>

Node::Node(int val) : data(val), left(nullptr), right(nullptr) {}

Node* buildTree(const int* values, int size) {
    if (size == 0) return nullptr;
    Node* root = new Node(values[0]);
    Node* current = root;
    int idx = 1;

    while (idx < size) {
        // Сначала левая дочерняя вершина - лист.
        current->left = new Node(values[idx++]);
        if (idx >= size) break;

        // Потом правая дочерняя вершина.
        current->right = new Node(values[idx++]);
        current = current->right;  // Движемся по дереву вправо.
    }

    return root;
}

void printTree(Node* root, std::string prefix, bool isLeft) {
    if (root == nullptr) return;
    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──");
    std::cout << root->data << std::endl;
    printTree(root->left, prefix + (isLeft ? "│   " : "    "), true);
    printTree(root->right, prefix + (isLeft ? "│   " : "    "), false);
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
