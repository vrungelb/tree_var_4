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

    bool isLeaf = (root->left == nullptr && root->right == nullptr);
    if (isLeaf) {
        std::cout << "\033[1;32m"; // Устанавливаем зеленый жирный цвет для листа
    }

    std::cout << root->data;

    if (isLeaf) {
        std::cout << "\033[0m";
    }

    std::cout << std::endl;

    printTree(root->left, prefix + (isLeft ? "│   " : "    "), true);
    printTree(root->right, prefix + (isLeft ? "│   " : "    "), false);
}



void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
