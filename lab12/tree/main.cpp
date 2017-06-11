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
        std::cout<< "Znalazlo";
    tree::InOrder(tree);

    return 0;
}