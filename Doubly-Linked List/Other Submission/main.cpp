#include <iostream>
using namespace std;

#include "IntList.h"

int main() {
    cout << "Enter a test number(1-3): ";
    int test;
    cin >> test;
    cout << endl;
    //tests constructor, destructor, push_front, pop_front, display
    if (test == 1) {
        cout << "\nlist1 constructor called" << flush;
        IntList list1;
        cout << "\npushfront 10" << flush;
        list1.push_front(10);
        cout << "\npushfront 20" << flush;
        list1.push_front(20);
        cout << "\npushfront 30" << flush;
        list1.push_front(30);
        cout << "\nlist1: " << flush;
        list1.printReverse();
        cout << "\npop" << flush;
        list1.pop_front();
        cout << "\nlist1: " << flush;
        list1.printReverse();
        cout << "\npop" << flush;
        list1.pop_front();
        cout << "\nlist1: " << flush;
        list1.printReverse();
        cout << "\npop" << flush;
        list1.pop_front();
        cout << "\nlist1: " << flush;
        list1.printReverse();
        cout << endl;
    }
    if (test == 1) {
        cout << "list1 destructor called" << endl;
    }

    //tests push_back
    if (test == 2) {
        cout << "\nlist2 constructor called" << flush;
        IntList list2;
        cout << "\npushback 10" << flush;
        list2.push_back(10);
        cout << "\npushback 20" << flush;
        list2.push_back(20);
        cout << "\npushback 30" << flush;
        list2.push_back(30);
        cout << "\nlist2: " << flush;
        list2.printReverse();
        cout << "\npop" << flush;
        list2.pop_front();
        cout << "\nlist2: " << flush;
        list2.printReverse();
        cout << "\npop" << flush;
        list2.pop_front();
        cout << "\nlist2: " << flush;
        list2.printReverse();
        cout << "\npop" << flush;
        list2.pop_front();
        cout << "\nlist2: " << flush;
        list2.printReverse();
        cout << endl;
    }
    if (test == 2) {
        cout << "list2 destructor called" << endl;
    }

    //tests selection_sort
    if (test == 3) {
        cout << "\nlist3 constructor called" << flush;
        IntList list3;
        cout << "\npushfront 10" << flush;
        list3.push_front(10);
        cout << "\npushfront 20" << flush;
        list3.push_front(20);
        cout << "\npushfront 30" << flush;
        list3.push_front(30);
        cout << "\nlist3: " << flush;
        list3.printReverse();
        cout << "\nlist3: " << flush;
        list3.printReverse();
        cout << "\npop" << flush;
        list3.pop_front();
        cout << "\npop" << flush;
        list3.pop_front();
        cout << "\npop" << flush;
        list3.pop_front();
        cout << "\nlist3: " << flush;
        list3.printReverse();
        cout << "\nlist3: " << flush;
        list3.printReverse();
        cout << "\npushfront 10" << flush;
        list3.push_front(10);
        cout << "\nselection_sort()" << flush;
        list3.printReverse();
        cout << "\nlist3: " << flush;
        list3.printReverse();
        cout << "\npushfront 20" << flush;
        list3.push_front(20);
        cout << "\nlist3: " << flush;
        list3.printReverse();
        cout << "\nselection_sort()" << flush;
        list3.printReverse();
        cout << "\nlist3: " << flush;
        list3.printReverse();
        cout << endl;
    }
    if (test == 3) {
        cout << "list3 destructor called" << endl;
    }


    return 0;
}