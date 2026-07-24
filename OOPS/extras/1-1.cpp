#include <iostream>
using namespace std;

class Bank
{
private:
    long acc_no;
    float bal;

public:
    void accept()
    {
        cout << "Enter account number: ";
        cin >> acc_no;
        cout << "Enter balance: ";
        cin >> bal;
    }

    void display()
    {
        cout << "Account Number: " << acc_no << endl;
        cout << "Balance: " << bal << endl;
    }
} b1, b2;

int main()
{
    cout << "Account-1:" << endl;
    b1.accept();

    cout << "\nAccount-2:" << endl;
    b2.accept();

    cout << endl
         << "Account-1 Details:" << endl;
    b1.display();
    cout << endl
         << "Account-2 Details:" << endl;
    b2.display();
    return 0;
}