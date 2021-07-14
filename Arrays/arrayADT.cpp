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

void Append(struct Array *arr) {

    int n;
    cout << "Enter the element to be appended into the array: ";
    cin >> n;

    if(arr->length < arr->size) {
        arr->A[arr->length++] = n;
    }
    else {
        cout << "There is no space in the array to append the new element" << endl;
    }
}

void Insert(struct Array *arr) {

    int index, n;
    cout << "Enter the index to which element is to be inserted: ";
    cin >> index;
    cout << "Enter the element to be appended into the array: ";
    cin >> n;

    if(arr->length < arr->size) {
        if(index >= 0 && index <= arr->length) {
            for(int i = arr->length; i > index; i--) {
                arr->A[i] = arr->A[i-1];
            }
            arr->A[index] = n;
            arr->length++;
        }
    }
}

int Delete(struct Array *arr) {
    int index, x;
    cout << "Enter the index at which element is to be deleted: ";
    cin >> index;

    if(index >= 0 && index < arr->length) {
        x = arr->A[index];
        for(int i = index; i < arr->length-1; i++) {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;

        return x;
    }

    else {
        cout << "Unable to find the entered index\n";

        return 0;
    }
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

    Append(&arr);
    Insert(&arr);
    Delete(&arr);
    Display(arr);

    return 0;
}