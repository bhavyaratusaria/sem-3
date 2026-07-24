#include <iostream>
using namespace std;

int main()
{
    float cel;
    cout << "Enter degree celsius: ";
    cin >> cel;

    cout << "Fahrenheit:" << (cel * 9.0 / 5.0) + 32;
    return 0;
}