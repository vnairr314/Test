/** Essential Concepts **/



#include <iostream>
#include <string>
using namespace std;

void arrayExample() {

    int size;
    cout << "Enter the size of your array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements in the array in each line\n";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "----Array----\n";
    for(int i = 0; i < size; i++) {
        cout << "Pos " << i << ": " << arr[i] << endl;
    }

}

void structExample() {

    struct Rectangle {
        int length;
        int breadth;
    };

    struct Rectangle R = {10, 5};
    R.breadth = 10;
    R.length = 15;

    cout << "Area of the ractangle is " << R.length * R.breadth << endl;

    struct Student {
        string name;
        string email;
        long int ID;
    };

    cout << endl << endl;

    int n, choice;
    cout << "How many students are there? ";
    cin >> n;
    struct Student s[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter details of student " << i+1 << ":" << endl << endl;
        cout << "Name: ";
        cin >> s[i].name;
        cout << "ID: ";
        cin >> s[i].ID;
        cout << "Email: ";
        cin >> s[i].email;
    }

    cout << "Which Student's information would you like to retrieve? ";
    cin >> choice;
    if(choice <= n) {
        cout << "Information for student " << choice << endl << endl;
        cout << s[choice-1].name << endl;
        cout << s[choice-1].ID << endl;
        cout << s[choice-1].email << endl;
    }
    else {
        cout << "You have entered an invalid selection, exiting...\n";
        cout << "Goodbye\n";
    }
}

void pointerExample() {

    int a1 = 10;
    int *p1 = &a1;

    int a2[5] = {1, 2, 3, 4, 5};
    int *p2 = a2;                   //Do not use the '&' symbol when dereferencing an array variable

    int *p3 = new int[5];           //Creating array in heap memory

    delete []p3;                    //Deleting memory in the heap

    int a3 = 10;
    int &r = a3;

    int b = 25;
    r = b;

    /** Executing lines 89-93 the values of the variables will be as follows:
     * a = 25
     * r = 25
     * b = 25
     */

}

void pointerToStruct() {

    struct Rectangle {
        int length;
        int breadth;
    };

    struct Rectangle R = {10, 5};
    struct Rectangle *p = &R;

    struct Rectangle *ptr;

    R.length = 20;          //Reassigning the value using struct variable
    (*p).length = 25;       //Reassigning the value using pointer to the struct variable
}

int passByValue(int a, int b) {
    int sum = a + b;
    return sum;
}

void passByAddress(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void passByReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void arrayAsParameter(int arr[], int n) {
    cout << "Elements of the array" << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

int *returnArray(int arr[], int n) {
    cout << "Manipulating array elements" << endl;
    for(int i = 0; i < n; i++) {
        arr[i] = arr[i] + 1;
    }

    return arr;
}

struct Rectangle {
    int length;
    int breadth;
};

int structAsParameter(struct Rectangle R) {
    int area = R.length * R.breadth;
    return area;
}

void structByAddress(struct Rectangle *R, int newLength, int newBreadth) {
    R->length = newLength;
    R->breadth = newBreadth;
}

int main() {

    //arrayExample();

    //structExample();

    /**
    int sum = passByValue(10, 5);
    cout << sum << endl;

    int x = 10, y = 5;
    passByAddress(&x, &y);  // Swapping values
    cout << "x = " << x << ", y = " << y << endl;

    passByReference(x, y);
     **/

    int arr[5] = {1, 3, 5, 7, 9};

    //arrayAsParameter(arr, 5); // Arrays can only be passed by address

    int *newArr = returnArray(arr, 5);

    for(int i = 0; i < 5; i++) {
        cout << newArr[i] << endl;
    }

    struct Rectangle R = {10, 5};
    int area = structAsParameter(R);
    //Calling by value - if any changes made inside the func, it will not change the original value
    //If calling by reference, it will change the original values
    cout << "Area of rectangle = " << area << endl;

    structByAddress(&R, 20, 10);
    cout << "New length = " << R.length << endl;
    cout << "New breadth = " << R.breadth << endl;

    return 0;
}

