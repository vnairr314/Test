//
// Created by Varun Nair on 1/2/21.
//

#include <iostream>

using namespace std;

int binarySearch(int arr[], int arrSize, int val) {

    int low = 0;
    int high = arrSize - 1;
    int mid;
    int foundIndex;
    bool flag = false;

    while((flag == false) && (low <= high)) {
        mid = (low + high)/2;
        if(val == arr[mid]) {

            flag = true;
            foundIndex = mid;
        }
        else if(val < arr[mid]) {

            high = mid - 1;
        }
        else {

            low = mid + 1;
        }
    }

    if(flag == true) {
        return foundIndex;
    }
    else {
        return -1;
    }
}

int main() {

    int arr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int val;

    cout << "Enter the value to search for: ";
    cin >> val;

    int index = binarySearch(arr, 10, val);

    if(index == -1) {
        cout << "The element was not found in the array\n";
    }
    else {
        cout << "The element was found at index " << index << endl;
    }

    return 0;

}
