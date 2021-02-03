//
// Created by Varun Nair on 1/27/21.
//

#include <iostream>
#include <vector>

using namespace std;

void merge(int arr[], int lowLeft, int highLeft, int highRight) {

    int lowRight = highLeft + 1;
    int size = highRight - lowLeft + 1;

    int leftIndex = lowLeft;
    int rightIndex = lowRight;
    int resultIndex = 0;

    int *mergedArray = new int[size];

    while(leftIndex <= highLeft && rightIndex <= highRight) {
        if(arr[leftIndex] < arr[rightIndex]) {
            mergedArray[resultIndex] = arr[leftIndex];
            leftIndex++;
            resultIndex++;
        }
        else {
            mergedArray[resultIndex] = arr[rightIndex];
            rightIndex++;
            resultIndex++;
        }
    }

    while(leftIndex <= highLeft) {
        mergedArray[resultIndex] = arr[leftIndex];
        leftIndex++;
        resultIndex++;
    }
    while(rightIndex <= highRight) {
        mergedArray[resultIndex] = arr[rightIndex];
        rightIndex++;
        resultIndex++;
    }

    for(int i = 0, iArr = lowLeft; i < size; i++, iArr++) {
        arr[iArr] = mergedArray[i];
    }

    delete []mergedArray;
}

void mergeSort(int arr[], int low, int high) {

    int mid;
    if(low == high) {
        return;
    }
    else {
        mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void printArray(int arr[], int arrSize) {
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

    mergeSort(arr, 0, n - 1);
    cout << "The sorted array is: " << endl;
    printArray(arr, n);

    return 0;
}