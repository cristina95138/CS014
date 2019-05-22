//
// Created by Cristina Lawson on 2019-05-18.
//

#ifndef MOVIE_REVIEW_SENTIMENT_ANALYSIS_WORDENTRY_H
#define MOVIE_REVIEW_SENTIMENT_ANALYSIS_WORDENTRY_H


#include <string>
#include <vector>
#include <iostream>

using namespace std;

class WordEntry {

private:
    string word;
    int numAppearances;
    int totalScore;
public:
    WordEntry(const string &, int);
    void addNewAppearance(int);
    const string & getWord();
    double getAverage();
};


#endif //MOVIE_REVIEW_SENTIMENT_ANALYSIS_WORDENTRY_H
