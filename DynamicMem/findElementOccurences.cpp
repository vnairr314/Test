/**
 Write a program that reads from the user a sequence of positive integers ending with -1, and another positive integer
 'num' that the user wishes to search for. The program should then print all the line numbers in sequence entered by
 the user that contain 'num' or a message saying that 'num' does not appear in the sequence
 Implement it without using the vector data structure
**/

#include <iostream>
#include <vector>
using namespace std;

int *createSequence(int &arrSize) {

    int *arr = new int[1];
    int size = 1;
    int element = 0;

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        //element++;
        if(arr[i] != -1) {
            element++;
            int *tempArr;
            tempArr = new int[size*2];
            for(int j = 0; j < element; j++) {
                tempArr[j] = arr[j];
            }
            delete []arr;
            arr = tempArr;
            size *= 2;
        }
        else {
            break;
        }

    }
    arrSize = element;
    return arr;

}

void findElement(int *arr, int arrSize, int num) {

    bool flag = true;
    cout << num << " shows up in lines ";
    for(int i = 0; i < arrSize; i++) {
        if(num == arr[i]) {
            cout << (i+1) << " ";
        }
        else{
            continue; // Need to add better handling in case num does not exist in sequence
        }
    }
    cout << endl;

}

void printArray(int *arr, int arrSize) {

    cout << "Number of elements = " << arrSize << endl;
    cout << "Sequence of numbers: [";
    for(int i = 0; i < arrSize; i++) {
        if(i == arrSize-1) {
            cout << arr[i] << "]" << endl;
        }
        else {
            cout << arr[i] << ", ";
        }
    }
}

int main() {

    int arrSize;
    int num;

    cout << "Please enter a sequence of positive integers, each in a separate line.\nEnd your input by typing -1\n";
    int *sequence = createSequence(arrSize);

    cout << "Enter the number you want to search for: ";
    cin >> num;

    findElement(sequence, arrSize, num);
    //printArray(sequence, arrSize);
    delete []sequence;

    return 0;

}
