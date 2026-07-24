#include <iostream>
using namespace std;

int main()
{
    int l, b;
    cout << "Enter length and breadth: ";
    cin >> l >> b;

    cout << "Area:" << l * b << endl;
    cout << "Perimeter:" << 2 * (l + b) << endl;
    return 0;
}
