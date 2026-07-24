#include <iostream>
using namespace std;

int main()
{
    float P, R;
    int T;
    cout << "Enter Principal, Rate of Interest and Time: ";
    cin >> P >> R >> T;
    cout << "Simple Interest= $" << (P * R * T) / 100;
    return 0;
}
