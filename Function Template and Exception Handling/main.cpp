#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;


template<typename T> unsigned min_index(const vector<T> &vals, unsigned index);

template<typename T> void selection_sort(vector<T> &vals);

template<typename T> T getElement(vector<T> vals, int index);

vector<char> createVector();


int main() {

    //Part B
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    while(--numOfRuns >= 0){
        cout << "Enter a number: " << endl;
        cin >> index;
        try {
            curChar = getElement(vals, index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
        catch (out_of_range& excpt) {
            cout << "Out of range exception occurred." << endl;
        }
    }

//    //Selection Sort Test Harness:
//
//    for (unsigned i = 0; i < vals.size(); ++i) {
//        cout << vals.at(i);
//    }
//
//    selection_sort(vals);
//
//    cout << endl;
//
//    for (unsigned i = 0; i < vals.size(); ++i) {
//        cout << vals.at(i);
//    }

    return 0;
}

template<typename T> unsigned min_index(const vector<T> &vals, unsigned index) {
    unsigned min = index;

    for(unsigned i = index; i < vals.size(); ++i) {
        if (vals.at(min) > vals.at(i)) {
            index = i;
        }
    }

    return index;
}

template<typename T> void selection_sort(vector<T> &vals) {
    int minI = 0;

    for(unsigned i = 0; i + 1 < vals.size(); ++i) {
        minI = i;
        for (unsigned j = i + 1; j < vals.size(); ++j) {
            if (vals.at(minI) > vals.at(j)) {
                minI = j;
            }
        }
        swap(vals.at(i), vals.at(minI));
    }
}

template<typename T> T getElement(vector<T> vals, int index) {
    return vals.at(index);
}

vector<char> createVector() {
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }

//    //Selection Sort Test Harness:
//    vals.push_back('b');
//    vals.push_back('f');
//    vals.push_back('c');
//    vals.push_back('a');
//    vals.push_back('e');
//    vals.push_back('d');

    return vals;
}