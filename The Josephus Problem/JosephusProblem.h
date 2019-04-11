//
// Created by Cristina Lawson on 2019-04-07.
//

#include <iostream>
using namespace std;

#ifndef THE_JOSEPHUS_PROBLEM_JOSEPHUSPROBLEM_H
#define THE_JOSEPHUS_PROBLEM_JOSEPHUSPROBLEM_H

struct Node {
    string data;
    Node* prev;
    Node *next;
    Node(string data) : data(data), prev(0), next(0) {}
};

class JosephusProblem {
private:
    Node* head;
    Node* tail;
    Node* curr;
    Node* off;
    int n; //size
    int pos; //position
    char direction;
    int k; //skipped

public:
    JosephusProblem();
    void make();
    void play();
    void printCircle();
    void printSurvivor() const;
    void push_back(string);
    bool empty() const;
    void setSize(int);
    void setPosition(int);
    void setDirection(char);
    void setSkipped(int);
    void remove();

};


#endif //THE_JOSEPHUS_PROBLEM_JOSEPHUSPROBLEM_H
