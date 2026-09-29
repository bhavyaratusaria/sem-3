#include <iostream>
using namespace std;
// Write a program to count the number of objects created using a static data member without using static member function or constructor

class Count
{
    static int count;

public:
    Count()
    {
        count++;
    }
    void disp()
    {
        cout << "No. of objects created: " << count << endl;
    }
};

int Count::count = 0;

int main()
{
    Count c1;
    c1.disp();
    Count c2;
    c2.disp();
    Count c3;
    c3.disp();
    return 0;
}