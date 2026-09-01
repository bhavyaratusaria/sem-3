#include <iostream>
using namespace std;
// WAP to create a class student having data members as roll-no,name and percentage.
// Accept data for 10 students and display names of students having percentage greater than 75.
class Student
{
    int roll, per;
    string name;

public:
    void acc()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll No.: ";
        cin >> roll;
        cout << "Enter Percentage: ";
        cin >> per;
    }
    void disp()
    {
        if (per > 74)
        {
            cout << "Name: " << name << endl;
            cout << "Roll No.: " << roll << endl;
            cout << "Percentage: " << per << endl;
        }
    }
} s[10];

int main()
{
    int i;
    cout << "Enter 10 Student Details: ";
    for (i = 0; i < 10; i++)
    {
        cout << endl
             << "Student " << i + 1 << endl;
        s[i].acc();
    }
    cout << endl;
    cout << "Student Details: " << endl;

    for (i = 0; i < 10; i++)
    {
        s[i].disp();
        cout << endl;
    }
    return 0;
}