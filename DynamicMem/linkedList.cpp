//
// Created by Varun Nair on 2/23/21.
//

#include <iostream>
#include <string>

using namespace std;

// Designing a linked list class
// A linked list is a data structure that can store an indefinite amount of items
// These items are connected using pointers in a sequential manner

// ----------- Singly-linked list -------------

struct node {
    int data;
    node *next;
};

class linkedList {
private:
    node *head, *tail;

public:
    linkedList() {

        head = NULL;
        tail = NULL;
    }

    void createNode(int value) {

        node *temp = new node;
        temp->data = value;
        temp->next = NULL;

        if(head == NULL) {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    void display() {

        node *temp = new node;
        temp = head;

        while(temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    }

    void insert_at_start(int value) {

        node *temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    void insert_at_position(int pos, int value) {

        node *previous = new node;
        node *current = new node;
        node *temp = new node;

        current = head;
        for(int i = 1; i < pos; i++) {
            previous = current;
            current = current->next;
        }

        temp->data = value;
        previous->next = temp;
        temp->next = current;
    }

    void delete_first() {

        node *temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }

    void delete_last() {

        node *current = new node;
        node *previous = new node;
        current = head;

        while(current->next != NULL) {
            previous = current;
            current = current->next;
        }
        tail = previous;
        previous->next = NULL;
        delete current;
    }

    void delete_position(int pos) {

        node *current = new node;
        node *previous = new node;
        current = head;

        for(int i = 1; i < pos; i++) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
    }
};

int main() {

    linkedList object;
    int nodes, nodeVal, pos;

    cout << "Enter the number of nodes you would like to create: ";
    cin >> nodes;

    for(int i = 0; i < nodes; i++) {
        cout << "Enter value of node: ";
        cin >> nodeVal;
        object.createNode(nodeVal);
    }

    cout << "\n\n";
    cout << "--------Displaying all Nodes--------" << endl;
    object.display();
    cout << endl << endl;

    cout << "--------Inserting a Node at the End--------" << endl;
    cout << "Enter value of node to be inserted: ";
    cin >> nodeVal;
    object.createNode(nodeVal);
    cout << endl << endl;

    cout << "--------Inserting a Node at the Start--------" << endl;
    cout << "Enter value of node to be inserted: ";
    cin >> nodeVal;
    object.insert_at_start(nodeVal);
    cout << endl << endl;

    cout << "--------Inserting a Node at a Position--------" << endl;
    cout << "Enter position where node has to be inserted: ";
    cin >> pos;
    cout << "Enter value of node to be inserted: ";
    cin >> nodeVal;
    object.insert_at_position(pos, nodeVal);
    cout << endl << endl;

    cout << "--------Deleting the first Node--------" << endl;
    object.delete_first();
    cout << endl;

    cout << "--------Deleting the last Node--------" << endl;
    object.delete_last();
    cout << endl;

    cout << "--------Deleting a Node at a Position--------" << endl;
    cout << "Enter position where node has to be deleted: ";
    cin >> pos;
    object.delete_position(pos);
    cout << endl;

    cout << "--------Displaying Updated Nodes--------" << endl;
    object.display();

    return 0;
}
