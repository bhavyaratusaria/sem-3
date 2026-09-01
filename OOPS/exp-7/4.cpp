#include <iostream>
using namespace std;
// WAP to calculate weight of object at different planets, using formula Weight = m x g
// where m = mass of object and g = gravitational force. Declare m as static member variable.
class Weight
{
    static float m;
    float g;

public:
    void acc()
    {
        cout << "Enter Mass: ";
        cin >> m;
        cout << "Enter Gravitational Force: ";
        cin >> g;
    }
    void disp()
    {
        cout << "Weight = " << m * g;
    }
} w1;

float Weight::m = 10.0;

int main()
{
    w1.acc();
    w1.disp();
    return 0;
}