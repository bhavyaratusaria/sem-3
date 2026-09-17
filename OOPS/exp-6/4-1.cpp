#include <iostream>
using namespace std;

class second;
class first
{
    string name;
    int sal;

public:
    void accept();
    friend void display(first f, second s);
} f1;

class second
{
    string name;
    int sal;

public:
    void accept();
    friend void display(first f, second s);
} s1;

void first::accept()
{
    cout << "Employee 1:" << endl;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter salary: ";
    cin >> sal;
}
void second::accept()
{
    cout << "Employee 2:" << endl;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter salary: ";
    cin >> sal;
}

void display(first f, second s)
{
    cout << endl
         << "Employee 1:" << endl;
    cout << "Name: " << f.name << endl;
    cout << "Salary: " << f.sal << endl;
    cout << "Employee 2:" << endl;
    cout << "Name: " << s.name << endl;
    cout << "Salary: " << s.sal << endl;
}

int main()
{
    cout << "Enter employee details: " << endl;
    f1.accept();
    s1.accept();
    display(f1, s1);
    return 0;
}
