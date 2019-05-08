//
// Created by Cristina Lawson on 2019-04-22.
//

#include <iostream>

using namespace std;

#ifndef TEMPLATE_STACK_STACK_H
#define TEMPLATE_STACK_STACK_H

const int MAX_SIZE = 20;

template<typename T>
class stack {
private:

    T data[MAX_SIZE];
    int size;

public:

    stack() {
        size = 0;
    }

    void push(T val) {
        if (size == MAX_SIZE) {
            throw overflow_error("Called push on full stack.");
        }
        data[size] = val;
        ++size;
    }

    void pop() {
        if (size > 0) {
            --size;
        }
        else {
            throw underflow_error("Called pop on empty stack.");
        }
    }

    T top() {
        T val;

        if (size > 0) {
            val = data[size - 1];
        }
        else {
            throw underflow_error("Called top on empty stack.");
        }
        return val;
    }

    bool empty() {
        if (size == 0) {
            return true;
        }
        return false;
    }
};

#endif //TEMPLATE_STACK_STACK_H
