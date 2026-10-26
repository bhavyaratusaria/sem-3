#include <iostream>
using namespace std;
// Overload a function to calculate the maximum of two integers and two floating-point numbers.

void max(int a, int b)
{
    if (a > b)
    {
        cout << "1st integer is greatest." << endl;
    }
    else
    {
        cout << "2nd integer is greatest." << endl;
    }
}

void max(float a, float b)
{
    if (a > b)
    {
        cout << "1st float is greatest." << endl;
    }
    else
    {
        cout << "2nd float is greatest." << endl;
    }
}

int main()
{
    max(19, 02);
    max(42.4f, 42.3f);
    return 0;
}