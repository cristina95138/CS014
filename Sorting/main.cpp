#include <iostream>
using namespace std;

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
const int NUMBERS_SIZE = 50000;

int genRandInt(int low, int high);
void fillArrays(int arr1[], int arr2[],int arr3[]);
void Quicksort_midpoint(int numbers[], int i, int k);
void Quicksort_medianOfThree(int numbers[], int i, int k);
void InsertionSort(int numbers[], int numbersSize);
int Partition_midpoint(int numbers[], int i, int k);
int Partition_medianOfThree(int numbers[], int i, int k);

int main() {
    srand(time(0));
    int elapsedTime = 0;
    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];

    fillArrays(arr1, arr2, arr3);

    //Quicksort_midpoint Unsorted
    clock_t Start = clock();
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE - 1);
    clock_t End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Quicksort_midpoint, Unsorted Time: " << elapsedTime << endl;

    //Quicksort_medianOfThree Unsorted
    Start = clock();
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE - 1);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS;
    cout << "Quicksort_medianOfThree, Unsorted Time: " << elapsedTime << endl;

    //InsertionSort Unsorted
    Start = clock();
    InsertionSort(arr3, NUMBERS_SIZE - 1);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS;
    cout << "InsertionSort, Unsorted Time: " << elapsedTime << endl;

    //Quicksort_midpoint Sorted
    Start = clock();
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE - 1);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS;
    cout << "Quicksort_midpoint, Sorted Time: " << elapsedTime << endl;

    //Quicksort_medianOfThree Sorted
    Start = clock();
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE - 1);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS;
    cout << "Quicksort_medianOfThree, Sorted Time: " << elapsedTime << endl;

    //InsertionSort Sorted
    Start = clock();
    InsertionSort(arr3, NUMBERS_SIZE - 1);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS;
    cout << "InsertionSort, Sorted Time: " << elapsedTime << endl;

    return 0;
}

void Quicksort_midpoint(int numbers[], int i, int k) {
    int j = 0;

    if (i >= k) {
        return;
    }

    j = Partition_midpoint(numbers, i, k);

    Quicksort_midpoint(numbers, i, j);
    Quicksort_midpoint(numbers, j + 1, k);
}

void Quicksort_medianOfThree(int numbers[], int i, int k) {
    int j = 0;

    if (i >= k) {
        return;
    }

    j = Partition_medianOfThree(numbers, i, k);

    Quicksort_medianOfThree(numbers, i, j);
    Quicksort_medianOfThree(numbers, j + 1, k);
}

int Partition_midpoint(int numbers[], int i, int k) {
    int a = i;
    int b = k;
    int midpoint = 0;
    int pivot = 0;
    bool finished = false;

    midpoint = (i + k) / 2;
    pivot = numbers[midpoint];

    while (!finished) {
        while (numbers[a] < pivot) {
            ++a;
        }

        while (pivot < numbers[b]) {
            --b;
        }

        if (a >= b) {
            finished = true;
        }
        else {
            swap(numbers[a], numbers[b]);
            ++a;
            --b;
        }
    }

    return b;
}

int Partition_medianOfThree(int numbers[], int i, int k) {
    int a = i;
    int b = k;
    int midpoint = 0;
    int pivot = 0;
    int right = 0;
    int left = 0;
    bool finished = false;

    midpoint = numbers[(i + k) / 2];
    right = numbers[i];
    left = numbers[k];

    if (midpoint < right && right <= left) {
        pivot = right;
    }
    else if (midpoint < left && left <= right) {
        pivot = left;
    }
    else if (midpoint == right || left == midpoint) {
        pivot = midpoint;
    }
    else if (right < midpoint && midpoint <= left) {
        pivot = midpoint;
    }
    else if (right < left && left <= midpoint) {
        pivot = left;
    }
    else if (right == midpoint || right == left) {
        pivot = right;
    }
    else if (left < right && right <= midpoint) {
        pivot = right;
    }
    else if (left < midpoint && midpoint <= right) {
        pivot = midpoint;
    }
    else if (left == right || midpoint == left) {
        pivot = left;
    }
    else {
        cout << right << " " << midpoint << " " << left << endl;
    }

    while (!finished) {
        while (numbers[a] < pivot) {
            ++a;
        }

        while (pivot < numbers[b]) {
            --b;
        }

        if (a >= b) {
            finished = true;
        }
        else {
            swap(numbers[a], numbers[b]);
            ++a;
            --b;
        }
    }

    return b;
}

void InsertionSort(int numbers[], int numbersSize) {
    int i = 0;
    int j = 0;

    for (i = 1; i < numbersSize; ++i) {
        j = i;

        while (j > 0 && numbers[j] < numbers[j - 1]) {
            swap(numbers[j], numbers[j - 1]);
            --j;
        }
    }
}

int genRandInt(int low, int high) {
    return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]) {
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}