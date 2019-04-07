//
// Created by Cristina Lawson on 2019-04-06.
//

#include <iostream>
using namespace std;

#ifndef DOUBLY_LINKEDLIST_INTLIST_H
#define DOUBLY_LINKEDLIST_INTLIST_H

struct IntNode {
    int data;
    IntNode *prev;
    IntNode *next;
    IntNode(int data) : data(data), prev(0), next(0) {}
};

class IntList {

private:
    IntNode* dummyHead;
    IntNode* dummyTail;
    IntNode* head;
    IntNode* tail;

public:
    IntList();
    ~IntList();
    void push_front(int);
    void pop_front();
    void push_back(int);
    void pop_back();
    bool empty() const;
    friend ostream & operator<<(ostream &out, const IntList &rhs);
    void printReverse() const;
};


#endif //DOUBLY_LINKEDLIST_INTLIST_H
