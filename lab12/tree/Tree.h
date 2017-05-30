//
// Created by bruzpatr on 30.05.17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H
#include <cstddef>
#include <initializer_list>
#include <algorithm>
template <class T>
class MyTree {
public:
    class Node{
    public:
        Node* left=nullptr;
        Node* right=nullptr;
        Node* parent= nullptr;
        T value_;
        bool operator>(Node n) {
            return (value_>n.value_);
        }
        bool operator==(Node n) {
            return (value_==n.value_);
        }
        bool operator<(Node n) {
            return (value_<n.value_);
        }

    };
    Node* root_;
    int size_=0;
    MyTree()=default;


    Node* Search(T value) {
        MyTree::Node* tmp=root_;
        if (tmp->value_==value)
            return root_;
        while (tmp!= nullptr and tmp->value_!=value) {
            if (value < tmp->value_)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        return tmp;
    }


    void Insert(T value) {
        Node n;
        n.value_=value;
        if (size_==0) {
            root_=&n;
            size_++;
        }
        else {
            MyTree::Node* tmp=root_;
            int last=0;
            while(tmp!= nullptr){
                if(n<*tmp) {
                    tmp = tmp->left;
                    last=0;
                }
                else {
                    tmp = tmp->right;
                    last=1;
                }
            }
            if (last==0)
                tmp=&n;
            else
                tmp=&n;
            n.parent=tmp->parent;
            size_++;
        }
    }


};
#endif //JIMP_EXERCISES_TREE_H
