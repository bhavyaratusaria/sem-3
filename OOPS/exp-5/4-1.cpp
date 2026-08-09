#include <iostream>
using namespace std;
// 4. Write an inline function to calculate simple interest.
class si
{
    float p, r, t;

public:
    void accept();
    void display();
} s1;

inline void si::accept()
{
    cout << "Enter principal: ";
    cin >> p;
    cout << "Enter rate: ";
    cin >> r;
    cout << "Enter time: ";
    cin >> t;
}
inline void si::display()
{
    cout << "Simple Interest: " << (p * r * t) / 100;
}
int main()
{
    s1.accept();
    s1.display();
    return 0;
}
