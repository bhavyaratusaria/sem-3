#include <iostream>
using namespace std;

// Write a Program to create a class College having data members as name, id, department.
// Use concept of constructor with default argument to set the value for college name as 'MIT Polytechnic'.
// Accept and display data for three objects.

class College
{
    int id;
    string name, dep;

public:
    College(int i = 10, string d = "HOD", string n = "MIT Polytechnic")
    {
        id = i;
        dep = d;
        name = n;
    }
    void display()
    {
        cout << "College: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Department: " << dep << endl;
    }
};

int main()
{
    College c1, c2(20, "CSE"), c3(30, "ECE", "MIT Engineering");
    c1.display();
    c2.display();
    c3.display();
    return 0;
}