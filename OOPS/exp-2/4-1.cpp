#include <iostream>
using namespace std;

// Define function outside the class
class Student
{
public:
    int roll, marks;
    string name;

    void accept();
    void display();
} s1;

void Student::accept()
{
    cout << "Enter roll no.: ";
    cin >> roll;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter marks: ";
    cin >> marks;
}

void Student::display()
{
    cout << "Roll no.: " << roll << endl;
    cout << "Name: " << name << endl;
    cout << "Marks: " << marks;
}
int main()
{
    s1.accept();
    s1.display();
    return 0;
}