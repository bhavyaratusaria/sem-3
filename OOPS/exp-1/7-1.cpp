#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float lA, aR, mR, t, emi;

    cout << "Enter loan amount: ";
    cin >> lA;
    cout << "Enter interest rate: ";
    cin >> aR;
    cout << "Enter time in months: ";
    cin >> t;

    mR = (aR / 12.0) / 100;
    emi = (lA * mR * pow(1 + mR, t)) / (pow(1 + mR, t) - 1);

    cout << "EMI: " << emi;
    return 0;
}