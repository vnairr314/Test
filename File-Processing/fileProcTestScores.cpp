//
// Created by Varun Nair on 1/30/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void openInputFile(ifstream &inFile) {

    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    inFile.open(filename);

    while(!inFile) {
        cout << "Unable to open the file. Try again\n";
        cout << "Enter the filename: ";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }

}

struct Student {
    int id;
    double testScore;
    string name;
};

int main() {

    ifstream inFile;
    openInputFile(inFile);

    vector <Student> v;
    Student temp;

    while(inFile >> temp.id) {
        inFile >> temp.testScore;
        inFile.ignore(9999, '\t');
        getline(inFile, temp.name);
        v.push_back(temp);
    }

    cout << "Students with test scores over 90:\n";
    for(Student s: v) {
        if(s.testScore > 90) {
            cout << s.name << endl;
        }
    }

    return 0;
}