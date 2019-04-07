//
// Created by Cristina Lawson on 2019-04-06.
//

#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList() {
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);

    dummyHead->prev = nullptr;
    dummyHead->next = dummyTail;

    dummyTail->prev = dummyHead;
    dummyTail->next = nullptr;

    head = dummyHead;
    tail = dummyTail;
}

IntList::~IntList() {
    while (!empty()) {
        pop_front();
    }
    delete dummyHead;
    delete dummyTail;
}

void IntList::push_front(int value) {
    IntNode* temp = new IntNode(value);

    if (empty()) {
        dummyHead->next = temp;
        temp->prev = dummyHead;
        temp->next = dummyTail;
        dummyTail->prev = temp;
    }
    else {
        temp->next = dummyHead->next;
        dummyHead->next->prev = temp;
        dummyHead->next = temp;
        temp->prev = dummyHead;
    }
}

void IntList::pop_front() {
    IntNode* temp = dummyHead->next;

    if (empty()) {

    }
    else {
        dummyHead->next = temp->next;
        temp->next->prev = dummyHead;
        delete temp;
        temp = nullptr;
    }
}

void IntList::push_back(int value) {
    IntNode* temp = new IntNode(value);

    if (empty()) {
        push_front(value);
    }
    else {
        temp->next = dummyTail;
        temp->prev = dummyTail->prev;
        dummyTail->prev = temp;
        temp->prev->next = temp;
    }
}

void IntList::pop_back() {
    IntNode* prevNode = dummyTail->prev;

    if (!empty()) {
        dummyTail->prev = prevNode->prev;
        prevNode->prev->next = dummyTail;
        delete prevNode;
        prevNode = nullptr;
    }
}

bool IntList::empty() const {
    if (dummyHead->next != dummyTail && dummyTail->prev != dummyHead) {
        return false;
    }
    else {
        return true;
    }
}

ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode* i = nullptr;
    IntNode* outNode = rhs.dummyHead;

    for (i = outNode->next; i != rhs.dummyTail; i = i->next) {
        out << i->data;
        if (i->next != rhs.dummyTail) {
            out << " ";
        }
    }
    return out;
}

void IntList::printReverse() const {
    IntNode* i = nullptr;

    for (i = dummyTail->prev; i != dummyHead; i = i->prev) {
        cout << i->data;
        if (i->prev != dummyHead) {
            cout << " ";
        }
    }
}