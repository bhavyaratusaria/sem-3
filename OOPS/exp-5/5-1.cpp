#include <iostream>
using namespace std;

class Swap
{
    int n1, n2, temp;

public:
    void swap();
    void accept();
    void display();
} s1;
inline void Swap::accept()
{
    cout << "Enter 1st number: ";
    cin >> n1;
    cout << "Enter 2nd number: ";
    cin >> n2;
}
inline void Swap::swap()
{
    temp = n1;
    n1 = n2;
    n2 = temp;
}
inline void Swap::display()
{
    cout << "After swap" << endl;
    cout << "Number 1: " << n1 << endl;
    cout << "Number 2: " << n2 << endl;
}
int main()
{
    s1.accept();
    s1.swap();
    s1.display();
    return 0;
}