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
        cout << "Enter Gravitational Force: ";
        cin >> g;
    }
    void disp()
    {
        cout << "Weight = " << m * g << endl;
    }
    static void mass()
    {
        cout << "Enter Mass of Object: ";
        cin >> m;
    }
} w1, w2;

float Weight::m = 0.0;

int main()
{
    Weight::mass();
    w1.acc();
    w1.disp();
    w2.acc();
    w2.disp();
    return 0;
}