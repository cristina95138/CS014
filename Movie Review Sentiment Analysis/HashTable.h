//
// Created by Cristina Lawson on 2019-05-18.
//

#ifndef MOVIE_REVIEW_SENTIMENT_ANALYSIS_HASHTABLE_H
#define MOVIE_REVIEW_SENTIMENT_ANALYSIS_HASHTABLE_H


#include <string>
#include <list>
#include <iostream>
#include "WordEntry.h"

using namespace std;

class HashTable {

private:
    list<WordEntry> *hashTable;
    int size;

public:
    HashTable(int);
    bool contains(const string &);
    double getAverage(const string &);
    void put(const string &, int);

private:
    int computeHash(const string &);
};


#endif //MOVIE_REVIEW_SENTIMENT_ANALYSIS_HASHTABLE_H
