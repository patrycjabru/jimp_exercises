//
// Created by patrycja on 18.03.17.
//

#include "SmartTree.h"
namespace datastructures {

    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        std::unique_ptr<SmartTree> leaf = std::make_unique<SmartTree>();
        leaf->value=value;
        return leaf;
    }

    std::unique_ptr<SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
        (*tree).left=move(left_subtree);
        return tree;
    }

    std::unique_ptr<SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
        (*tree).right=move(right_subtree);
        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
        if (unique_ptr->left!= nullptr) {
            PrintTreeInOrder(unique_ptr->left, out);
        }
        *out << (*unique_ptr).value << ", ";
        if (unique_ptr->right!= nullptr) {
            PrintTreeInOrder(unique_ptr->right, out);
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {
        std::string str = "";
        if (tree!= nullptr) {
            std::stringstream ss;
            std::string str1;
            ss << (*tree).value;
            ss >> str1;
            str = "[" + str  + str1 +" "+ DumpTree((*tree).left) + DumpTree((*tree).right) + "]";
        }
        else {
            str=" [none]";
        }
        return str;
    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree)
    {
//
//        for(int i=0;i<tree.length();i++)
//        {
//            if(tree[i]=='[')
//            {
//                std::string str="";
//                i+=1;
//                while(tree[i]!=' ')
//                    str+=tree[i];
//                std::stringstream ss;
//                int temp;
//                ss << str;
//                ss >> temp;
//                CreateLeaf(temp);
//                InsertLeftChild()
//            }
//
//        }
        return 0;
    }
}