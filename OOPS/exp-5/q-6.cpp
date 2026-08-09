#include <iostream>
using namespace std;

class greatest
{
    int n1, n2, n3;

public:
    void great();
    void accept();
    void display();
} g1;
inline void greatest::accept()
{
    cout << "Enter 1st number: ";
    cin >> n1;
    cout << "Enter 2nd number: ";
    cin >> n2;
    cout << "Enter 3rd number: ";
    cin >> n3;
}
inline void greatest::display()
{
    if (n1 > n2 && n1 > n3)
        cout << n1 << " is greatest.";
    else if (n2 > n1 && n2 > n3)
        cout << n2 << " is greatest.";
    else
        cout << n3 << " is greatest.";
}

int main()
{
    g1.accept();
    g1.display();
    return 0;
}