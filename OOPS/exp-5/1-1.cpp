#include <iostream>
using namespace std;
// 1. Write a program to calculate the cube of a number using an inline function.
class cube
{
    int num;

public:
    void accept();
    void display();
} c1;

inline void cube::accept()
{
    cout << "Enter number: ";
    cin >> num;
}
inline void cube::display()
{
    cout << "Cube is: " << num * num * num;
}
int main()
{
    c1.accept();
    c1.display();
    return 0;
}