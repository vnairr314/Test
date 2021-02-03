/**
 Implement the following recursive functions:
 1. Input a positive integer n and print a textual image of a right triangle aligned to the left, made of n lines with asterisks
 2. Input a positive integer n and print a textual image of two opposite right triangles aligned to the left, with asterisks. each containing n lines
 3. Input a positive integer n and print a vertical ruler of 2n-1 lines with each line containing '-' according to the following rules:
    a. The line in the middle(1/2) of the ruler contains n '-' symbols
    b. The line at the middle of each half(1/4 & 3/4) of the ruler contains (n-1) '-' symbols
    c. The lines at 1/8, 3/8, 5/8, 7/8 of the ruler contains (n-2) '-' symbols
    d. All other points should contain 1 '-' symbol

 */

#include <iostream>
using namespace std;

void printTriangle(int n) {

    if(n == 1) {
        cout << "*";
        cout << endl;
    }
    else {
        printTriangle(n-1);
        for(int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;
    }

}

void printOppositeTriangle(int n) {

    if(n == 1) {
        cout << "*";
        cout << endl;
    }
    else {
        for(int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;
        printOppositeTriangle(n-1);
    }

    for(int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
}

void printRuler(int n) {

    if(n <= 0) {
        return;
    }
    else {
        printRuler(n-1);
        for(int i = 0; i < n; i++) {
            cout << "-";
        }
        cout << endl;
    }
    printRuler(n-1);
}

int main() {

    int n;
    cout << "Enter the (positive) number of lines for right triangle: ";
    cin >> n;
    printTriangle(n);

    int m;
    cout << "Enter the (positive) number of lines for the opposite right triangle: ";
    cin >> m;
    printOppositeTriangle(m);

    int l;
    cout << "Enter positive integer to print ruler: ";
    cin >> l;
    printRuler(l);

    return 0;

}



