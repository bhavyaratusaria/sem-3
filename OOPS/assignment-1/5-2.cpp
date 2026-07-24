#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter 2 numbers to swap: ";
    cin >> a >> b;
    swap(a, b);
    cout << "a=" << a << endl;
    cout << "b=" << b;
    return 0;
}
