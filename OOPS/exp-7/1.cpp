#include <iostream>
using namespace std;
// WAP to define a class SI having data members as principal, duration, and rate of interest.
// Declare rate of interest as static member variable. Calculate the SI and display it.

class SI
{
    float p, d;
    static float r;

public:
    void acc()
    {
        cout << "Enter Principal: ";
        cin >> p;
        cout << "Enter Duration: ";
        cin >> d;
    }
    void disp()
    {
        cout << "Simple Interest = " << (p * d * r) / 100;
    }
} s1;
float SI::r = 5.0; // Initialize the static member variable

int main()
{
    s1.acc();
    s1.disp();
    return 0;
}