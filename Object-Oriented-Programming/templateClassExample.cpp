#include <iostream>
using namespace std;

template <class T>
class Arithmetic {
private:
    T a;
    T b;

public:
    Arithmetic(T a, T b);
    T add();
    T subtract();

};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b) {
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add() {
    T c;
    c = a + b;
    return c;
}

template <class T>
T Arithmetic<T>::subtract() {
    T c;
    c = a - b;
    return c;
}

int main() {

    Arithmetic<double> A(5.7, 10.4);

    cout << "The sum of numbers are " << A.add() << endl;
    cout << "The difference of the numbers are " << A.subtract() << endl;

    return 0;
}

