//
// Created by Cristina Lawson on 2019-04-06.
//

#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList() {
    dummyHead = nullptr;
    dummyTail = nullptr;
}

IntList::~IntList() {
    while (dummyHead != nullptr) {
        pop_front();
    }
}

void IntList::push_front(int value) {
    IntNode* temp = new IntNode(value);

    if (dummyHead == nullptr) {
        dummyHead = temp;
        dummyTail = temp;
    }
    else {
        temp->next = dummyHead;
        dummyHead->prev = temp;
        dummyHead = temp;
    }
}

void IntList::pop_front() {
    IntNode* temp = nullptr;

    if (dummyHead != nullptr) {
        temp = dummyHead;
        dummyHead = dummyHead->next;
        if (dummyHead != nullptr) {
            dummyHead->prev = nullptr;
        }
        else {
            dummyTail = nullptr;
        }
        delete temp;
    }
}

void IntList::push_back(int value) {
    IntNode* temp = new IntNode(value);

    if (dummyTail == nullptr) {
        dummyHead = temp;
        dummyTail = temp;
    }
    else {
        dummyTail->next = temp;
        temp->prev = dummyTail;
        dummyTail = temp;
    }
}

void IntList::pop_back() {
    IntNode* temp = dummyTail;

    if (!empty()) {

        if (dummyHead == dummyTail) {
            delete temp;
            dummyHead = nullptr;
            dummyTail = nullptr;
        }
        else {
            dummyTail = dummyTail->prev;
            dummyTail->next = nullptr;
            delete temp;
        }
    }
}

bool IntList::empty() const {
    if (dummyHead == nullptr && dummyTail == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode *outNode = rhs.dummyHead;

    while (outNode != nullptr) {
        out << outNode->data;
        if (outNode->next != nullptr) {
            out << " ";
        }
        outNode = outNode->next;
    }
    return out;
}

void IntList::printReverse() const {
    IntNode* i = nullptr;

    for (i = dummyTail; i != nullptr; i = i->prev) {
        cout << i->data;
        if (i->prev != nullptr) {
            cout << " ";
        }
    }
}