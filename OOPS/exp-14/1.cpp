#include <iostream>
using namespace std;

// Write a program to calculate the area of a square, rectangle, and circle using function overloading.

void area(int s)
{
    cout << "Square Area = " << s * s << endl;
}
void area(int l, int b)
{
    cout << "Rectangle Area = " << l * b << endl;
}
void area(float r)
{
    float PI = 3.14;
    cout << "Circle Area = " << PI * r * r << endl;
}

int main()
{
    area(5);
    area(5, 6);
    area(4.5f);
    return 0;
}