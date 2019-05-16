//
// Created by Cristina Lawson on 2019-05-10.
//

#include "Heap.h"

Heap::Heap() {
    numItems = 0;

    for (unsigned i = 0; i < MAX_HEAP_SIZE; ++i) {
        arr[i] = 0;
    }
}

void Heap::enqueue (PrintJob* node) {
    if (numItems != MAX_HEAP_SIZE) {
        if (numItems == 0) {
            arr[0] = node;
            ++numItems;
        } else {
            arr[numItems] = node;
            swap(numItems);
            ++numItems;
        }
    }
}

void Heap::dequeue () {
    if (numItems == 0) {
        return;
    }
    else if (numItems == 1) {
        numItems = 0;
        arr[numItems] = 0;
    }
    else {
        arr[0] = arr[numItems - 1];
        --numItems;
        trickleDown(0);
    }
}

PrintJob* Heap::highest () {
    if (numItems != 0) {
        return arr[0];
    }

    return 0;
}

void Heap::print () {
    if (numItems != 0) {
        cout << "Priority: " << arr[0]->getPriority() << ", Job Number: " << arr[0]->getJobNumber() << ", Number of Pages: " << arr[0]->getPages() << endl;
    }
}

void Heap::trickleDown(int val) {

    if ((val * 2) + 1 > numItems || (val * 2) + 2 > numItems) {
        return;
    }
    if (arr[(val * 2) + 2] == 0) {
        swap((val * 2) + 1);
        trickleDown((val * 2) + 1);

    } else if (arr[(val * 2) + 1]->getPriority() > arr[(val * 2) + 2]->getPriority()) {
        swap((val * 2) + 1);
        trickleDown((val * 2) + 1);
    } else {
        swap((val * 2) + 2);
        trickleDown((val * 2) + 2);
    }
}

void Heap::swap(int nodeI) {
    PrintJob* temp = nullptr;

    if (nodeI == 0) {
        return;
    }
    else if (arr[nodeI]->getPriority() > arr[(nodeI - 1) / 2]->getPriority()) {
        temp = arr[nodeI];
        arr[nodeI] = arr[(nodeI - 1) / 2];
        arr[(nodeI - 1) / 2] = temp;

        if((nodeI - 1) / 2 != 0) {
            swap((nodeI - 1) / 2);
        }
    }
}