#include <iostream>
using namespace std;
// WAP to create a class staff having data member as name,post and salary.Accept data for 5
// staff and display the staff details having post = “HOD”

class Staff
{
    int sal;
    string name, post;

public:
    void acc()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Post: ";
        cin >> post;
        cout << "Enter Salary: ";
        cin >> sal;
    }
    void disp()
    {
        if (post == "HOD")
        {
            cout << "Name: " << name << endl;
            cout << "Post: " << post << endl;
            cout << "Salary: " << sal << endl;
        }
    }
} e[5];

int main()
{
    int i;
    cout << "Enter 5 Staff Details: ";
    for (i = 0; i < 5; i++)
    {
        cout << endl
             << "Staff " << i + 1 << endl;
        e[i].acc();
    }
    cout << endl;
    cout << "Staff Details: " << endl;

    for (i = 0; i < 5; i++)
    {
        e[i].disp();
        cout << endl;
    }
    return 0;
}