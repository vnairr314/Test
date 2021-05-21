#include <iostream>
using namespace std;

int sum(int n) {
    if(n == 0) {
        return 0;
    }
    else {
        return sum(n-1) + n;
    }
}

int factorial(int n) {
    if(n == 0) {
        return 1;
    }
    else {
        return factorial(n-1) * n;
    }
}

int pow(int n, int m) {
    if(n == 0) {
        return 0;
    }
    if(m == 0) {
        return 1;
    }
    else {
        return pow(n, m-1) * n;
    }
}

int fibonacci(int n) {
    if(n <= 1) {
        return n;
    }
    else {
        return fibonacci(n-2) + fibonacci(n-1);
    }
}



