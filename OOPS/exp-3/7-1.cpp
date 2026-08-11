#include <iostream>
using namespace std;
// Write a c++ code to create a class which calculates area of a circle.

class Circle
{
    float r;
    const float PI = 3.1415;

public:
    void accept()
    {
        cout << "Enter radius in cm: ";
        cin >> r;
    }
    void display()
    {
        cout << "Area of circle = " << PI * r * r;
    }
} c1;

int main()
{
    c1.accept();
    c1.display();
    return 0;
}