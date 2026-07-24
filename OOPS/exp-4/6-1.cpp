#include <iostream>
using namespace std;
// Write a program to calculate square of number in which define class and
// define member function inside the class as per requirement.

class Square
{
    int num;

public:
    void accept()
    {
        cout << "Enter number: ";
        cin >> num;
    }
    void display()
    {
        cout << "Square of number is: " << num * num;
    }

} s1;

int main()
{
    s1.accept();
    s1.display();
    return 0;
}
