#include <iostream>
using namespace std;

// Find the area of rectangle by casting double data into float and integer type.
int main()
{
    double l, w;
    cout << "Enter length and width in cm: ";
    cin >> l >> w;

    cout << "Rectangle Area (float): " << (float)l * (float)w << endl;
    cout << "Rectangle Area (int): " << (int)l * (int)w;
    return 0;
}