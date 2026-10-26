#include <iostream>
using namespace std;

// Write a program to overload a function for calculating the volume of a cube and cuboid.

void vol(int s)
{
    cout << "Cube Area = " << s * s * s << endl;
}
void vol(int l, int b, int h)
{
    cout << "Cuboid Area = " << l * b * h << endl;
}

int main()
{
    vol(5);
    vol(2, 3, 4);
    return 0;
}