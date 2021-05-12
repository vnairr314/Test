/**
 * Recursion
 */

#include <iostream>
using namespace std;

void tailRecursion(int n) {
    if(n > 0) {
        cout << "Value of n is " << n << endl;
        tailRecursion(n-1);
    }

}

void headRecursion(int n) {
    if(n > 0) {
        headRecursion(n-1);
        cout << "Value of n is " << n << endl;
    }

}

void treeRecursion(int n) {
    if(n > 0) {
        cout << "Value of n is " << n << endl;
        treeRecursion(n-1);
        treeRecursion(n-1);
    }
}

void indirectRecursionB(int n);
void indirectRecursionA(int n) {
    if(n > 0) {
        cout << "Value of n is: " << n << endl;
        indirectRecursionB(n-1);
    }
}

void indirectRecursionB(int n) {
    if(n > 0) {
        cout << "Value of n is: " << n << endl;
        indirectRecursionA(n/2);
    }
}

int nestedRecursion(int n) {
    if(n > 100) {
        return (n - 10);
    }
    else {
        return nestedRecursion(nestedRecursion(n+11));
    }
}

int main() {

    //tailRecursion(5);
    //headRecursion(5);
    //treeRecursion(4);
    //indirectRecursionA(20);
    cout << "Return Value for nested recursion is: " << nestedRecursion(95) << endl;

    return 0;
}
