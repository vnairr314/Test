//Lots of errors - needs fixing


#include <iostream>
using namespace std;

class Array {

private:
    int *A;
    int size;
    int length;
public:
    Array() {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int size) {
        size = size;
        length = 0;
        A = new int[size];
    }

    ~Array() {
        delete[]A;
    }

    void Display();
};

void Array::Display() {

    cout << "Displaying struct parameters:\n";
    cout << "Size of the Array: " << size << endl;
    cout << "Length of the array (number of elements present): " << length << endl;
    cout << "Array elements: ";
    for(int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
}

void Reverse(struct Array *arr) {

    int temp;
    for(int i = 0, j = arr->size-1; i < j; i++, j--) {

        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }

    cout << "The reversed array is displayed below:" << endl;
    for(int i = 0; i < arr->size; i++) {
        cout << arr->A[i] << " ";
    }
    cout << endl;
}

struct Array *Merge(struct Array *arr1, struct Array *arr2) {

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;

    while(i < arr1->length && j < arr2->length) {
        if(arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        }
        else {
            arr3->A[k++] = arr2->A[j++];
        }
    }

    for(; i < arr1->length; i++) {
        arr3->A[k++] = arr1->A[i];
    }

    for(; j < arr2->length; j++) {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->size + arr2->size;

    return arr3;
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

    struct Array *arr1;
    struct Array *arr2 = {{1, 3, 5, 7, 9}, 10, 5};
    struct Array *arr3;

    //Reverse(&arr);

    arr3 = Merge(&arr1, &arr2);
    Display(*arr3);

    return 0;

}