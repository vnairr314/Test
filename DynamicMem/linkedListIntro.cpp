//
// Created by Varun Nair on 1/30/21.
//

/**
 * In a list, data is stored in a node (DATA)
 * Each node contains a data section and at least one pointer(if not multiple) to the next node (NEXT)
 * DATA stores just one item of the list
 * The pointers (NEXT) are connected to form a chain of nodes
 * The list is recorded by the HEAD - a pointer to the first node
 * The last node will point to nullptr

 ------------------------
 |           |          |
 |   DATA    |  NEXT    |
 |           |          |
 |           |          |
 |           |          |
 ------------------------

 **/


#include <iostream>
#include <string>
using namespace std;

/**
template <class T>
class LListNode {
    T data;
    LListNode<T>* next;

public:
    LListNode (T newdata = T(), LListNode<T>* newNext = nullptr) : data(newdata), next(newNext) {}
    friend class LList <T>;

    class LList {
        LListNode<T>* head;
        LListNode<T>* recursiveCopy(LListNode<T>* rhs);

    public:

    };
};
**/
int main() {

    cout << "Testing to see if this program will execute\n";

    return 0;
}