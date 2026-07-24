#include <iostream>
using namespace std;

// Find the area of rectangle by casting double data into float and integer type.
int main()
{
    double l, w;
    cout << "Enter length and width in cm: ";
    cin >> l >> w;

    cout << "Area: " << (float)l * (float)w << endl;
    cout << "Area: " << (int)l * (int)w;
    return 0;
}