#include <iostream>
using namespace std;
// Write a program to define a class student having data members name and roll no.
// Accept and display data for one object. Define the member function inside the class

class Student
{
    int roll;
    string name;

public:
    void accept()
    {
        cout << "Enter roll no.: ";
        cin >> roll;
        cout << "Enter name: ";
        cin >> name;
    }
    void display()
    {
        cout << "Roll No.: " << roll << endl;
        cout << "Name: " << name << endl;
    }
} s1;

int main()
{
    s1.accept();
    s1.display();
    return 0;
}
