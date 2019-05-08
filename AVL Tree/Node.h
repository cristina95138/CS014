//
// Created by Cristina Lawson on 2019-05-07.
//

#include <iostream>
using namespace std;

#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H


class Node {
    friend class AVLTree;

private:
    string data;
    int balance;
    Node* left;
    Node* right;
    Node* parent;

public:
    Node():data(""), balance(0), left(0),right(0), parent(0){}
    Node(const string& val):data(val), balance(0), left(0),right(0), parent(0){}
};


#endif //AVL_TREE_NODE_H
