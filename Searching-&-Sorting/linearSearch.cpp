//
// Created by Varun Nair on 12/28/20.
//

#include <iostream>
#include <string>
using namespace std;

int search(int arr[], int arrSize, int val) {

    int i = 0;
    while(i < arrSize) {
        if(arr[i] == val) {
            return i;
        }
        i++;
    }
    return -1;
}

int main() {

    int arrSize;
    cout << "Enter the size of the array: ";
    cin >> arrSize;

    int arr[arrSize];
    cout << "Enter the elements of the array:\n";
    for(int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    int val;
    cout << "Enter the number you want to search: ";
    cin >> val;

    int output = search(arr, arrSize, val);
    if(output == -1) {
        cout << "The element was not found in the array\n";
    }
    else {
        cout << "The element was found in position " << output << endl;
    }

    return 0;
}
