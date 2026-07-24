#include <iostream>
using namespace std;
// Develop a class Account to accept account details and display the balance using functions defined outside the class.

class Account
{
private:
    long acc_no;
    float bal;

public:
    void accept();
    void display();
} a1;

void Account::accept()
{
    cout << "Enter account number: ";
    cin >> acc_no;
    cout << "Enter balance: ";
    cin >> bal;
}
void Account::display()
{
    cout << "Account Number: " << acc_no << endl;
    cout << "Balance: " << bal << endl;
}

int main()
{
    a1.accept();
    a1.display();
    return 0;
}