#include <iostream>
using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr) {

    cout << "Displaying struct parameters:\n";
    cout << "Size of the Array: " << arr.size << endl;
    cout << "Length of the array (number of elements present): " << arr.length << endl;
    cout << "Array elements: ";
    for(int i = 0; i < arr.length; i++) {
        cout << arr.A[i] << " ";
    }
    cout << "\n";
}

int Get(struct Array arr) {

    int index;
    cout << "Enter the index of the element to be returned: ";
    cin >> index;

    if(index >= 0 && index < arr.length) {
        return arr.A[index];
    }
    else {
        cout << "Invalid index entered\n";
        return -1;
    }
}

void Set(struct Array *arr) {

    int index, x;
    cout << "Enter the index at which element is to be set: ";
    cin >> index;
    cout << "Enter the value of element to be set: ";
    cin >> x;

    if(index >= 0 && index < arr->length) {
        arr->A[index] = x;
    }
    else {
        cout << "Invalid index enetered\n";
    }
}

int Max(struct Array arr) {

    int max = arr.A[0];
    for(int i = 0; i < arr.length; i++) {
        if(arr.A[i] > max) {
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr) {

    int min = arr.A[0];
    for(int i = 1; i < arr.length; i++) {
        if(arr.A[i] < min) {
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr) {

    int sum = 0;
    for(int i = 0; i < arr.length; i++) {
        sum += arr.A[i];
    }
    return sum;
}

float Average(struct Array arr) {

    float avg;
    float sum = 0;
    int count = 0;
    for(int i = 0; i < arr.length; i++) {
        sum += arr.A[i];
        count++;
    }
    avg = sum/count;
    return avg;
}

int main() {

    struct Array arr;
    cout << "Enter the size of the array: ";
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;

    cout << "Enter number of elements to be input: ";
    cin >> arr.length;
    cout << "Enter the elements of the array:\n";
    for(int i = 0; i < arr.length; i++) {
        cin >> arr.A[i];
    }


    cout << "Output of Get function: " << Get(arr) << endl;
    Set(&arr);
    cout << "Max of the array: " << Max(arr) << endl;
    cout << "Min of the array: " << Min(arr) << endl;
    cout << "Sum of the array: " << Sum(arr) << endl;
    cout << "Average of the array: " << Average(arr) << endl;
    Display(arr);

    return 0;
}