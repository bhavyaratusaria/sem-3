#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int age;

public:
    void accept()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
} s1;

int main()
{
    s1.accept();
    s1.display();
    return 0;
}