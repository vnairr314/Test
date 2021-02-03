//
// Created by Varun Nair on 1/2/21.
//

#include <iostream>
#include <vector>

using namespace std;

int selectionSortSearch(int arr[], int low, int high) {
    int min = arr[low];
    int minIndex = low;

    for(int i = low+1; i <= high; i++) {
        if(arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void selectionSort(int arr[], int arrSize) {

    int minIndex;
    for(int i = 0; i < arrSize; i++) {
        minIndex = selectionSortSearch(arr, i, arrSize-1);
        swap(arr[i], arr[minIndex]);
    }

    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << endl;
    }
}

int main() {

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the values in the array\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "The sorted array is:\n";
    selectionSort(arr, n);

    return 0;
}
