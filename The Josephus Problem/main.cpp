#include <iostream>
using namespace std;

#include "JosephusProblem.h"

int main() {
    int n = 0; //size
    int pos = 0;
    char direction = ' ';
    int k; //skipped
    JosephusProblem problem;

    cout << "Enter the size (1 - 32): " << endl;
    cin >> n;
    while (n > 32) {
        cout << "Enter the size (1 - 32): " << endl;
        cin >> n;
    }
    problem.setSize(n);

    cout << "Enter the starting position (1 - " << n << "): " << endl;
    cin >> pos;
    while (pos > n || pos < 1) {
        cout << "Enter the starting position (1 - " << n << "): " << endl;
        cin >> pos;
    }
    problem.setPosition(pos);

    cout << "Enter the direction (L or R): " << endl;
    cin >> direction;
    while (!(direction == 'L' || direction == 'R')) {
        cout << "Enter the direction (L or R): " << endl;
        cin >> direction;
    }
    problem.setDirection(direction);

    cout << "Enter number to be skipped (0 - " << n << "): " << endl;
    cin >> k;
    while (k > n || k < 0) {
        cout << "Enter number to be skipped (0 - " << n << "): " << endl;
        cin >> k;
    }
    problem.setSkipped(k);

    problem.make();

    problem.play();

    cout << endl << endl << "Survivor: ";
    problem.printSurvivor();
    cout << endl;

    return 0;
}