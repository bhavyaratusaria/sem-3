#include <iostream>
using namespace std;

// Write a Program to demonstrate concept of copy constructor.

class A
{
    int n;

public:
    A(int num)
    {
        n = num;
    }
    A(A &a)
    {
        n = a.n;
    }
    void display()
    {
        cout << "n = " << n << endl;
    }
};

int main()
{
    A a1(29);
    A a2(a1);
    a1.display();
    a2.display();
    return 0;
}