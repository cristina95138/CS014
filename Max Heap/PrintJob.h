//
// Created by Cristina Lawson on 2019-05-10.
//

#ifndef MAX_HEAP_PRINTJOB_H
#define MAX_HEAP_PRINTJOB_H

#include <iostream>
using namespace std;

class PrintJob {
private:
    int priority;
    int jobNumber;
    int numPages;

public:
    PrintJob (int, int, int);
    int getPriority ();
    int getJobNumber ();
    int getPages ();
    //You can add additional functions here
};


#endif //MAX_HEAP_PRINTJOB_H
