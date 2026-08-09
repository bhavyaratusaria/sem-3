#include <iostream>
using namespace std;
// 2. Write an inline function to find the maximum of two numbers.
class greatest
{
public:
    int n1, n2;
    void accept();
    void display();
} g1;

inline void greatest::accept()
{
    cout << "Enter 1st number: ";
    cin >> n1;
    cout << "Enter 2nd number: ";
    cin >> n2;
}
inline void greatest::display()
{
    if (n1 > n2)
    {
        cout << "1st number is greater.";
    }
    else
    {
        cout << "2nd number is greater.";
    }
}
int main()
{
    g1.accept();
    g1.display();
    return 0;
}