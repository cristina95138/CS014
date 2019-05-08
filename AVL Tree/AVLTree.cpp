//
// Created by Cristina Lawson on 2019-05-07.
//

#include <iostream>
#include <fstream>
using namespace std;

#include "AVLTree.h"
#include "Node.h"


void AVLTree::rotate (Node* node) {
    if (balanceFactor(node) == 2) {
        if (balanceFactor(node->left) == 1) { // 2, 1 rotate right
            rotateRight(node);
        }
        else if (balanceFactor(node->left) == -1) { // 2, -1 rotate left, then right
            rotateLeft(node->left);
            rotateRight(node);

        }
    }

    if (balanceFactor(node) == -2) {
        if (balanceFactor(node->right) == 1) {
            rotateRight(node->right);
            rotateLeft(node);
        }
        else if (balanceFactor(node->right) == -1) {
            rotateLeft(node);
        }
    }
}

Node* AVLTree::rotateLeft (Node* node) {
    Node* nRoot = nullptr;

    nRoot = node->right;
    node->right = nRoot->left;

    if (node != root) {
        if (node->parent->left == node) {
            node->parent->left = nRoot;
        }

        if (node->parent->right == node) {
            node->parent->right = nRoot;
        }
    }

    nRoot->parent = node->parent;
    node->parent = nRoot;
    nRoot->left = node;

    if (node == root) {
        root = nRoot;
    }

    return nRoot;
}

Node* AVLTree::rotateRight (Node* node) {
    Node* nRoot = nullptr;

    nRoot = node->left;
    node->left = nRoot->right;

    if (node != root) {
        if (node->parent->left == node) {
            node->parent->left = nRoot;
        }

        if (node->parent->right == node) {
            node->parent->right = nRoot;
        }
    }

    nRoot->parent = node->parent;
    node->parent = nRoot;
    nRoot->right = node;

    if (node == root) {
        root = nRoot;
    }

    return nRoot;
}

void AVLTree::insert(const string &tS) {
    Node* unbalanced = nullptr;

    if (root == nullptr) {
        root = new Node(tS);
        return;
    }
    else {
        Node* curr = root;

        while (curr != nullptr) {
            if (tS == curr->data) {
                return;
            }

            if (tS < curr->data) {
                if (curr->left == nullptr) {
                    curr->left = new Node(tS);
                    curr->left->parent = curr;

                    unbalanced = nullptr;
                    unbalanced = findUnbalancedNode(curr->left);

                    if (unbalanced != nullptr) {
                        rotate(unbalanced);
                    }
                    return;
                }
                else {
                    curr = curr->left;
                }
            }
            else {
                if (curr->right == nullptr) {
                    curr->right = new Node(tS);
                    curr->right->parent = curr;

                    unbalanced = nullptr;
                    unbalanced = findUnbalancedNode(curr->right);

                    if (unbalanced != nullptr) {
                        rotate(unbalanced);
                    }

                    return;
                }
                else {
                    curr = curr->right;
                }
            }
        }
    }
}

Node* AVLTree::findUnbalancedNode (Node* node) {
    Node* curr = node;
    int balance;

    while (curr->parent != 0) {
        balance = balanceFactor(curr->parent);
        if (balance == 2 || balance == -2) {
            return curr->parent;
        }
        else {
            curr = curr->parent;
        }
    }

    return 0;
}

void AVLTree::printBalanceFactors(Node* node) {
    if (node) {
        printBalanceFactors(node->left);
        cout << node->data << "(" << balanceFactor(node) << "), ";
        printBalanceFactors(node->right);
    }
}

int AVLTree::balanceFactor(Node* node) {
    int left = height(node->left);
    int right = height(node->right);
    int total = left - right; //only 1, -1, 0 are valid
    return total;
}

void AVLTree::printBalanceFactors() {
    printBalanceFactors(root);
    cout << endl;
}

int AVLTree::height(Node* node) const {
    int left = 0;
    int right = 0;
    int total = 0;

    if (node != 0) {
        left = height(node->left);
        right = height(node->right);
        int height = max(left, right);
        total = height + 1;
    }

    return total;
}

void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;
        }
    }
}