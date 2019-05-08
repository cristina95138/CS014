//
// Created by Cristina Lawson on 2019-05-07.
//

#include <iostream>
using namespace std;

#include "Node.h"

#ifndef AVL_TREE_AVLTREE_H
#define AVL_TREE_AVLTREE_H


class AVLTree {

private:
    Node* root;
    Node* findUnbalancedNode (Node* node);
    void rotate (Node* node);
    Node* rotateLeft (Node* node);
    Node* rotateRight (Node* node);
    void printBalanceFactors(Node* node);
    void visualizeTree(ofstream &out, Node *n);
    int height(Node* node) const;

public:
    AVLTree():root(nullptr){}
    void insert(const string &);
    int balanceFactor(Node*);
    void printBalanceFactors();
    void visualizeTree(const string &);
};


#endif //AVL_TREE_AVLTREE_H
