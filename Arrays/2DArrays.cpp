#include <iostream>
using namespace std;

int  main() {

    int rows, columns;
    cout << "Enter rows and columns:\n";
    cin >> rows;
    cin >> columns;

    int A[rows][columns];

    int *B[rows];
    for(int i = 0; i < rows; i++) {
        B[i] = (int *)malloc(columns * sizeof(int));
    }

    int **C;
    C = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        C[i] = (int *)malloc(columns * sizeof(int));
    }

    cout << "-----Changing values in existing 2D arrays-----" << endl << endl;
    for(int i = 0; i < rows; i++) {
        cout << "Enter values in first row:" << endl;
        for(int j = 0; j < columns; j++) {
            cin >> B[i][j];  //replace with A or C to change the respective array elements
        }
    }

    cout << "-----Printing each 2D array (A, B, C)-----" << endl;
    cout << endl;

    cout << "Array A:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n\nArray B:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n\nArray C:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
