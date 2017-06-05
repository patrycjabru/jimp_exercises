//
// Created by bruzpatr on 30.05.17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H
#include <cstddef>
#include <initializer_list>
#include <algorithm>
#include <cmath>
namespace tree {
    template<class T>
    class Tree {
    public:
        class Node {
        public:
            Node *left = nullptr;
            Node *right = nullptr;
            Node *parent = nullptr;
            T value_;

            bool operator>(Node n) {
                return (value_ > n.value_);
            }

            bool operator==(Node n) {
                return (value_ == n.value_);
            }

            bool operator<(Node n) {
                return (value_ < n.value_);
            }

        };
        Node *root_;
        int size_ = 0;

        Tree() = default;
        Tree(T value) {
            Node* n = new Node;
            n->value_=value;
            root_=n;
            size_=1;
        }
//        ~Tree() {
//            Node* tmp=root_;
//            Node* tmp_left=root_->left;
//            Node* tmp_right=root_->right;
//            if (root_!= nullptr)
//                delete(root_);
//        }
        void deleteNodes(Node* n) {
            ;
        }
        T Value() {
            return root_->value_;
        }
        int Size() {
            return size_;
        }
        int Depth() {
            return log2(size_)+1;
        }
        Node *Search(T value) {
            if (size_==0)
                return nullptr;
            Tree::Node *tmp = root_;
            if (tmp->value_ == value)
                return root_;
            while (tmp != nullptr and tmp->value_ != value) {
                if (value < tmp->value_)
                    tmp = tmp->left;
                else
                    tmp = tmp->right;
            }
            return tmp;
        }


        void Insert(T value) {
            Node* n= new Node;
            n->value_=value;
            if(size_==0)
                root_=n;
            else {
                bool isRight= false;
                Node *tmp = root_;
                Node *prev = nullptr;
                if (*n < *tmp) {
                    prev = tmp;
                    tmp = tmp->right;
                    isRight = true;
                }
                else {
                    prev = tmp;
                    tmp = tmp->left;
                    isRight=false;
                }
                if(isRight)
                    prev->right=n;
                else
                    prev->left=n;
                n->parent=prev;
            }
            size_++;

        }
    };
}
#endif //JIMP_EXERCISES_TREE_H
