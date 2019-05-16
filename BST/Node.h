//
// Created by Cristina Lawson on 2019-04-25.
//

#include <iostream>
using namespace std;

#ifndef BST_NODE_H
#define BST_NODE_H


class Node {
    friend class BSTree;

private:
    string data;
    int count;
    Node* left;
    Node* right;
    Node* parent;

public:
    Node(string data):data(data), count(1), left(0),right(0), parent(0){}
};


#endif //BST_NODE_H
