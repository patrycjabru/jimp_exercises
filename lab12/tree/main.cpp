#include <iostream>
#include "Tree.h"

//
// Created by bruzpatr on 30.05.17.
//
int main() {
    tree::Tree<int> tree;
    tree.Insert(5);
    tree.Insert(10);
    tree.Insert(7);
    tree.Insert(34);
    tree.Insert(12);
    if (tree.Search(10)!= nullptr)
        std::cout<< "Znalazlo 10\n";
    if (tree.Search(40)!= nullptr)
        std::cout<< "Znalazlo 40\n";
    else
        std::cout<< "Nie znalazlo 40\n";
    std::cout << "InOrder:" << std::endl;
    tree::InOrder(tree);
    std::cout << "PreOrder:" << std::endl;
    tree::PreOrder(tree);
    std::cout << "PostOrder:" << std::endl;
    tree::PostOrder(tree);
    return 0;
}