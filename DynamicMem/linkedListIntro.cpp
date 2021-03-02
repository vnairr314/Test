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
#include <vector>
#include <string>
using namespace std;

template <class T>
class List {
private:
    struct Node {
        Node *Next{nullptr};
        T Data{};

        Node() = default; //Creating a default empty node

        explicit Node(const T& data) : Data {data} {}  //Creating a node storing input data

        Node(const T& data, Node *Next) : Data{data}, Next{next} {}  //Creating a node storing input data and pointing to another node
    };

    Node *node_head{nullptr};
    int node_count{0};

    List(const List&) = delete;
    List& operator = (const List&) = delete;

public:
    typedef Node *Position; // declaring the position type - representing the position of the node - its memory address - an observing row pointer to a node

    List() = default; //default constructor to create an empty list

    ~List() {
        Clear();
    }

    int Count() const {
        return node_count;
    }

    bool isEmpty() const {
        return (node_count == 0);
    }

    void Clear() {
        while(!isEmpty()) {
            removeHead();
        }
    }

    void insertHead(const T& value) {
        Node *node = new Node{value};

        node->Next = node_head; // Replacing the current head with the new head node
        node_head = node;
        node_count++;
    }

    void removeHead() {
        assert(!isEmpty()); // To make sure we are not using removeHead() on an empty list

        Node *newHead = node_head->next; // Save the pointer to the next node before removing the current head node
        delete node_head();
        node_head = newHead; // Updating head to point to the new head node
        node_count--;
    }

    T elementAt(Position node) {
        assert(!isEmpty());
    }

};


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


int main() {

    cout << "Testing to see if this program will execute\n";

    return 0;
}