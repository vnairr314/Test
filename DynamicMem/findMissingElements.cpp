/**
 Implement a function that gets an array of integers 'arr' and its logical size n -> {0,1,2,...,n}
 When called it should return a new array that contains all the numbers in range - {0,1,2,...,n} that are not in 'arr'
 The function should also update the output parameter 'resArrSize' with the logical size of the new array that was
 created.

**/

#include <iostream>
using namespace std;

int *findMissing(int arr[], int n, int &resArrSize) {

    int *missing = new int[1];
    int missingElements = 0;
    int arrSize = 1;
    bool flag = true;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != arr[j]) {
                flag = false;
            }
            else {
                flag = true;
                break;
            }
        }

        if(flag == false) {
            missing[missingElements] = i;
            missingElements++;
        }

        if(missingElements > 0) {
            int *tempArr;
            tempArr = new int[arrSize*2];
            for(int i = 0; i < missingElements; i++) {
                tempArr[i] = missing[i];
            }
            delete []missing;
            missing = tempArr;
            arrSize *= 2;
        }

    }

    resArrSize = missingElements;
    return missing;

}

void printElements(int *arr, int resArrSize) {

    cout << "Number of missing elements = " << resArrSize << endl;
    cout << "Missing elements = [";
    for(int i = 0; i < resArrSize; i++) {
        if(i == resArrSize-1) {
            cout << arr[i] << "]" << endl;
        }
        else {
            cout << arr[i] << ", ";
        }

    }
}

int main() {

    int n;
    cout << "Enter logical size of array: ";
    cin >> n;
    int arr[n];

    int resArrSize;

    cout << "Enter the elements in array\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int *finalArr = findMissing(arr, n, resArrSize);
    printElements(finalArr, resArrSize);

    delete []finalArr;
}