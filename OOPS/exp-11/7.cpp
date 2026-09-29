#include <iostream>
using namespace std;
// Write a C++ program with a base class A and a derived class B.
// Implement a basic constructor in both classes to show their execution order when an object of class B is created.

class A
{
public:
    A()
    {
        cout << "constructor A." << endl;
    }
};

class B : public A
{
public:
    B()
    {
        cout << "constructor B." << endl;
    }
};

int main()
{
    B b1;
    return 0;
}