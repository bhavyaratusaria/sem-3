#include <iostream>
using namespace std;
// WAP to create a class employee having data members as name id and department.
// Accept and display data for 5 employees.
class employee
{
    string name, dep;
    int id;

public:
    void acc()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Department: ";
        cin >> dep;
    }
    void disp()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Department: " << dep << endl;
    }
} e[5];

int main()
{
    int i;
    cout << "Enter 5 Employee Details: ";
    for (i = 0; i < 5; i++)
    {
        cout << endl
             << "Employee " << i + 1 << endl;
        e[i].acc();
    }
    cout << endl;
    cout << "Employee Details: " << endl;

    for (i = 0; i < 5; i++)
    {
        e[i].disp();
        cout << endl;
    }
    return 0;
}