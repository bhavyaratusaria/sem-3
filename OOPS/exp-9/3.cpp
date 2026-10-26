#include <iostream>
using namespace std;

// 3. Write a Program to create a class student having data members as roll_no, name and marks:
// a) Use default constructor to initialize the data members and display it.
// b) Use parameterized constructor to initialize the data members and display data for 2 students.

class Student
{
    int roll_no;
    string name;
    float marks;

public:
    // a
    Student()
    {
        roll_no = 1;
        name = "Om";
        marks = 80;
    }
    // b
    Student(int r, string n, float m)
    {
        roll_no = r;
        name = n;
        marks = m;
    }
    void display()
    {
        cout << "Roll No: " << roll_no << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
} s1, s2, s3;

int main()
{
    s2 = Student(55, "Bhavya", 84.1);
    s3 = Student(56, "Aarush", 96.2);
    s1.display();
    s2.display();
    s3.display();
    return 0;
}