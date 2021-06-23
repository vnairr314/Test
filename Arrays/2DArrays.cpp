#include <iostream>
using namespace std;

int  main() {

    int rows, columns;
    cout << "Enter rows and columns:\n";
    cin >> rows;
    cin >> columns;

    int A[rows][columns]; // initializing array in stack

    int *B[rows]; // initializing array in heap
    for(int i = 0; i < rows; i++) {
        B[i] = (int *)malloc(columns * sizeof(int));
    }

    int **C; // initializing array in heap (method 2)
    C = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        C[i] = (int *)malloc(columns * sizeof(int));
    }

    cout << "-----Printing each 2D array (A, B, C)-----" << endl;
    cout << endl;

    cout << "Array A:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << A[i][j] << " ";
        }
    }

    cout << "\n\nArray B:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << B[i][j] << " ";
        }
    }

    cout << "\n\nArray C:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << C[i][j] << " ";
        }
    }

    return 0;
}
