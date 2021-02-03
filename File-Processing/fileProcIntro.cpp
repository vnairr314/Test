//
// Created by Varun Nair on 1/27/21.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void openInputFile(ifstream &inFile) {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    inFile.open(filename);

    while(!inFile) {
        cout << "File failed to open, try again!\n";
        cout << "Enter the filename: ";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }

}

int main() {

    ifstream inFile;
    openInputFile(inFile);
    vector<int> v;

    int temp;
    while(inFile >> temp) {
        v.push_back(temp);
    }

    double sum = 0;
    for(int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    double avg = sum / v.size();

    cout << "The average of the integers in the file is: " << avg << endl;

    /**
    ofstream outFile;
    outFile.open("outFile.txt"); // Another method - ofstream outFile("outFile.txt")
    **/


    return 0;
}