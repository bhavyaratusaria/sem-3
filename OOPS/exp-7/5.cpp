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
} c1, c2, c3;

int main()
{
    c1.disp();
    c2.disp();
    c3.disp();
    return 0;
}