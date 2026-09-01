#include <iostream>
using namespace std;
// WAP to store details of five customers. Assume suitable data members.

class Customer
{
    string name;
    long phone;

public:
    void accept()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Phone No.: ";
        cin >> phone;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Phone No.: " << phone << endl;
    }
} c[5];

int main()
{
    int i;
    cout << "Enter 5 Customer Details: ";
    for (i = 0; i < 5; i++)
    {
        cout << endl
             << "Customer " << i + 1 << endl;
        c[i].accept();
    }
    cout << endl;
    cout << "Customer Details: " << endl;

    for (i = 0; i < 5; i++)
    {
        c[i].display();
        cout << endl;
    }
    return 0;
}