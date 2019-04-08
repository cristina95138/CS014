//
// Created by Cristina Lawson on 2019-04-06.
//

#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList() {
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);

    head = dummyHead;
    tail = dummyTail;

    head->prev = nullptr;
    head->next = tail;

    tail->prev = head;
    tail->next = nullptr;
}

IntList::~IntList() {
    while (!empty()) {
        pop_front();
    }
    delete head;
    delete tail;
}

void IntList::push_front(int value) {
    IntNode* temp = new IntNode(value);

    if (empty()) {
        head->next = temp;
        temp->prev = head;
        temp->next = tail;
        tail->prev = temp;
    }
    else {
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
    }
}

void IntList::pop_front() {
    IntNode* temp = head->next;

    if (empty()) {

    }
    else {
        head->next = temp->next;
        temp->next->prev = head;
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
        temp->next = tail;
        temp->prev = tail->prev;
        tail->prev = temp;
        temp->prev->next = temp;
    }
}

void IntList::pop_back() {
    IntNode* prevNode = tail->prev;

    if (!empty()) {
        tail->prev = prevNode->prev;
        prevNode->prev->next = tail;
        delete prevNode;
        prevNode = nullptr;
    }
}

bool IntList::empty() const {
    if (head->next != tail && tail->prev != head) {
        return false;
    }
    else {
        return true;
    }
}

ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode* i = nullptr;
    IntNode* outNode = rhs.head;

    for (i = outNode->next; i != rhs.tail; i = i->next) {
        out << i->data;
        if (i->next != rhs.tail) {
            out << " ";
        }
    }
    return out;
}

void IntList::printReverse() const {
    IntNode* i = nullptr;

    for (i = tail->prev; i != head; i = i->prev) {
        cout << i->data;
        if (i->prev != head) {
            cout << " ";
        }
    }
}