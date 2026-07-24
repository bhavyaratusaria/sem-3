#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter 3 numbers: ";
    cin >> a >> b >> c;

    if (a > b && a > c)
        cout << "1st number " << a << " is largest";
    else if (b > a && b > c)
        cout << "2nd number " << b << " is largest";
    else if (c > a && c > b)
        cout << "3rd number " << c << " is largest";
    else
        cout << "There are multiple largest numbers.";
    return 0;
}
