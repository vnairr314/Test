/**
 Write a program that reads from the user a sequence of positive integers ending with -1, and another positive integer
 'num' that the user wishes to search for. The program should then print all the line numbers in sequence entered by
 the user that contain 'num' or a message saying that 'num' does not appear in the sequence
 Implement it using the vector data structure
**/

#include <iostream>
#include <vector>
using namespace std;

vector <int>createSequence() {

    vector <int>Sequence;
    int n;
    cout << "Please enter a sequence of positive integers, each in a separate line.\nEnd your input by typing -1\n";
    while(n != -1) {
        cin >> n;
        Sequence.push_back(n);
    }

    return Sequence;
}

void searchInVector(vector <int>Sequence, int num) {
    cout << num << " shows up in lines ";
    for(int i = 0; i < Sequence.size(); i++) {
        if(num == Sequence[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {

    int num;
    vector <int>sequence = createSequence();

    cout << "Please enter the number you want to search for: ";
    cin >> num;
    searchInVector(sequence, num);

    return 0;
}


