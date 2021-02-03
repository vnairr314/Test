/**
 Program to demonstrate the workings of a basic class structure in C++
 */
#include <iostream>
using namespace std;

class DayOfYear {

public:
    void output(); //This is a member function declaration
    int day; // These are member variables
    int month;
};

void DayOfYear::output() {

    cout << "Month = " << month << ", " << "day = " << day;
    cout << endl;
}

int main() {

    DayOfYear today; // These are objects of the class 'DayOfYear'
    DayOfYear birthday;

    cout << "--Enter today's date--\n\n";
    cout << "Enter the month (in numbers): ";
    cin >> today.month;
    cout << "Enter the day (in numbers): ";
    cin >> today.day;

    cout << "\n--Enter your birthday--\n\n";
    cout << "Enter the month (in numbers): ";
    cin >> birthday.month;
    cout << "Enter the day (in numbers): ";
    cin >> birthday.day;

    cout << "Today's date: ";
    today.output();
    cout << "Your birth date: ";
    birthday.output();

    if(today.month == birthday.month && today.day == birthday.day) {
        cout << "Happy Birthday!\n";
    }
    else {
        cout << "Happy not birthday lol\n";
    }

    return 0;
}



