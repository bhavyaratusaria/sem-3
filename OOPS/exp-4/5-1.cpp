#include <iostream>
using namespace std;
// Write a program to calculate the area of a rectangle using functions defined outside the class.

class Rectangle
{
    int l, w;

public:
    void accept();
    void display();
} r1;

void Rectangle::accept()
{
    cout << "Enter length: ";
    cin >> l;
    cout << "Enter width: ";
    cin >> w;
}
void Rectangle::display()
{
    cout << "Area of rectangle: " << l * w;
}

int main()
{
    r1.accept();
    r1.display();
    return 0;
}