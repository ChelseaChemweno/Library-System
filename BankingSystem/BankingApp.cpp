#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountno;
    double balance;
    string owner;

public:
    
    BankAccount(int accNo, double bal, string name) {
        accountno = accNo;
        balance = bal;
        owner = name;
        cout << "Bank Account Created Successfully" << endl;
    }

   
    void displayDetails() {
        cout << "\nAccount Details:" << endl;
        cout << "Account Owner: " << owner << endl;
        cout << "Account Number: " << accountno << endl;
        cout << "Balance: " << balance << endl;
    }

    
    ~BankAccount() {
        cout << "\nAccount has been closed" << endl;
    }
};   


int main() {
    BankAccount account1(12345, 50000, "Chelsea Chemweno");

    account1.displayDetails();

    return 0;
}