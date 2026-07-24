#include <iostream>
using namespace std;
// Write a program to store and display student information using functions defined outside the class.

class Student
{
    string name;
    int age;

public:
    void accept();
    void display();
} s1;

void Student::accept()
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
}
void Student::display()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}

int main()
{
    s1.accept();
    s1.display();
    return 0;
}