//
// Created by Varun Nair on 12/28/20.
//

/**
 Program to demonstrate a class with functionality of a bank account
 **/

#include <iostream>
using namespace std;

class BankAccount {

public:
    BankAccount(int dollars, int cents, double rate); // constructor
    BankAccount(int dollars, double rate);
    BankAccount();
    // the member func 'set' is being overloaded
    void set(int dollars, int cents, double rate); // this func is used if customer enters dollars and cents
    void set(int dollars, double rate); // this func is used if the customer only enters dollars
    void update();
    double get_balance() const;
    double get_interestRate();
    void output();

private:
    double balance;
    double interest_rate;
    static double fraction(double percent); // this member func converts a percentage to a fraction
};

BankAccount::BankAccount(int dollars, int cents, double rate) {

    if((dollars > 0) && (cents > 0) && (rate > 0)) {
        balance = dollars + 0.01 * cents;
        interest_rate = rate;
    }
    else {
        cout << "You have entered impossible values, please start over\n";
        exit(1);
    }
}

BankAccount::BankAccount(int dollars, double rate) {

    if((dollars > 0) && (rate > 0)) {
        balance = dollars;
        interest_rate = rate;
    }
    else {
        cout << "You have entered impossible values, please start over\n";
        exit(1);
    }
}

BankAccount::BankAccount() {
    balance = 0;
    interest_rate = 0;
}

void BankAccount::set(int dollars, int cents, double rate) {

    if((dollars > 0) && (cents > 0) && (rate > 0)) {
        balance = dollars + 0.01 * cents;
        interest_rate = rate;
    }
    else {
        cout << "You have entered impossible values, please start over\n";
        exit(1);
    }
}

void BankAccount::set(int dollars, double rate) {

    if((dollars > 0) && (rate > 0)) {
        balance = dollars;
        interest_rate = rate;
    }
    else {
        cout << "You have entered impossible values, please start over\n";
        exit(1);
    }
}

void BankAccount::update() {

    balance = balance + (fraction(interest_rate) * balance);
}

double BankAccount::fraction(double percent) {

    return percent/100.0;
}

double BankAccount::get_balance() const {

    return balance;
}

double BankAccount::get_interestRate() {

    return interest_rate;
}

void BankAccount::output() {

    cout << "The account balance is: $" << balance << endl;
    cout << "The interest rate on your account is: " << interest_rate << "%" << endl;
}

int main() {

    BankAccount account1(100, 50, 2.5);
    BankAccount account2;

    cout << "---Starting the program---\n\n";
    //account1.set(100, 50, 2.5);
    cout << "The statement for account1:\n";
    account1.output();
    cout << "The statement for account2:\n";
    account2.output();

    return 0;
}
