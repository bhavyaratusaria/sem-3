#include <iostream>
using namespace std;
// Write a program to calculate the volume of a box using functions defined outside the class

class Box
{
    int l, w, h;

public:
    void accept();
    void display();
} b1;

void Box::accept()
{
    cout << "Enter width: ";
    cin >> w;
    cout << "Enter length: ";
    cin >> l;
    cout << "Enter height: ";
    cin >> h;
}
void Box::display()
{
    cout << "Area of box: " << l * w * h;
}

int main()
{
    b1.accept();
    b1.display();
    return 0;
}