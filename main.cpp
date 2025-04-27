#include "my_tree.h"
#include <iostream>
#include <vector>
#include <windows.h>

#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define RESET   "\033[0m"

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Node* root = nullptr;
    std::vector<int> values;
    int choice;

    do {
        std::cout << "\nМеню:\n"
                  << "1. Ввести N и значения\n"
                  << "2. Построить дерево\n"
                  << "3. Показать дерево\n"
                  << "4. Показать указатель на корень\n"
                  << "0. Выход\n"
                  << "Выберите пункт: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int n, val;
                std::cout << "Введите количество вершин (N): ";
                std::cin >> n;
                values.clear();
                for (int i = 0; i < n; ++i) {
                    std::cout << "Введите значение для вершины " << i + 1 << ": ";
                    std::cin >> val;
                    values.push_back(val);
                }
                break;
            }

            case 2:
                if (values.empty()) {
                    std::cout << RED << "Ошибка. Вы не ввели данные." << RESET << std::endl;
                } else {
                    if (root) {
                        deleteTree(root); // Удаляем старое дерево, если было
                        root = nullptr;
                    }
                    root = buildTree(values.data(), values.size());
                    std::cout << GREEN << "Дерево построено." << RESET << std::endl;
                }
                break;

            case 3:
                if (root) {
                    printTree(root);
                } else {
                    std::cout << RED << "Ошибка. Вы не построили дерево." << RESET << std::endl;
                }
                break;

            case 4:
                std::cout << "Указатель на корень: " << root << std::endl;
                break;

            case 0:
                std::cout << "Выход.\n";
                break;

            default:
                std::cout << "Неверный выбор.\n";
        }
    } while (choice != 0);


    if (root) {
        deleteTree(root);
    }
    return 0;
}
