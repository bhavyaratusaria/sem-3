#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter 2 numbers to swap: ";
    cin >> a >> b;
    c = a, a = b, b = c;
    cout << "a=" << a << endl;
    cout << "b=" << b;
    return 0;
}