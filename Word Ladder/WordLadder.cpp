// Collaborated with: STUDENT-SHARE https://drive.google.com/drive/folders/1znuqRm3JVPPWC1qQ1Fxcj0igW4l6Rtkx
//
// Created by Cristina Lawson on 2019-04-13.
//

#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

#include "WordLadder.h"


WordLadder::WordLadder(const string &inputFile) {
    ifstream in;
    string word;

    //cout << "Opening file " << inputFile << "." << endl;

    in.open(inputFile);

    if (!in.is_open()) {
        cout << "Could not open file " << inputFile << "." << endl;
        return;
        //exit(1);
    }

    while (in >> word) {
        if (word.length() != 5) {
            cout << "Must be 5 character word." << endl;
        }
        else {
            dict.push_back(word);
        }
    }
    in.close();
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    ofstream out;
    queue<stack<string> > iQueue;
    stack<string> iStack;
    string word;
    list<string>::iterator dinary;
    bool startP = false;
    bool endP = false;

    //cout << "Word ladder from " << start << " to " << end << "." << endl;

    //cout << "Opening file " << outputFile << "." << endl;

    out.open(outputFile);

    if (!out.is_open()) {
        cout << "Could not open file " << outputFile << "." << endl;
        return;
        //exit(1);
    }

    for (dinary = dict.begin(); dinary != dict.end(); ++dinary) {
        if (*dinary == start) {
            startP = true;
        }

        if (*dinary == end) {
            endP = true;
        }
    }

    if (!startP || !endP) {
        cout << "Not found.";
        return;
    }

    if (start == end) {
        out << start;
        return;
    }

    iStack.push(start);
    iQueue.push(iStack);

    dict.remove(start);

    while (!iQueue.empty()) {
        word = iQueue.front().top();
        for (dinary = dict.begin(); dinary != dict.end(); ++dinary) {
            if (check(word, *dinary)) {
                if (*dinary == end) {
                    iQueue.front().push(end);
                    print(iQueue.front(), out);
                    return;
                }
                iStack = iQueue.front();
                iStack.push(*dinary);
                iQueue.push(iStack);
                dinary = dict.erase(dinary);
                --dinary;
            }
        }
        iQueue.pop();
    }

    if (out.is_open()) {
        out << "No Word Ladder Found." << endl;
        cout << "No Word Ladder Found." << endl;
    }
    out.close();
}

bool WordLadder::check(string word, string dinaryWord) {
    int chter = 0;

    for (unsigned i = 0; i < 5; ++i) {
        if (word.at(i) == dinaryWord.at(i)) {
            ++chter;
        }
    }

    if (chter == 4) {
        return true;
    }
    else {
        return false;
    }
}

void WordLadder::print(stack<string> cStack, ofstream &out) {
    vector<string> wl;
    int iter = 0;

    while (!cStack.empty()) {
        wl.push_back(cStack.top());
        cStack.pop();
        ++iter;
    }

    if (out.is_open()) {
        while (iter != 0) {
            --iter;
            out << wl.at(iter);
            //cout << wl.at(iter);
            if (iter != 0) {
                out << " ";
                //cout << " ";
            }
        }
        //cout << endl;
    }
}