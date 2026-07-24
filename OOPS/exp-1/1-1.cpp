#include <iostream>
using namespace std;

int main()
{
    float basic, gross, hra, da;
    cout << "Enter Basic Salary: ";
    cin >> basic;

    hra = basic * 0.2;
    da = basic * 0.4;
    gross = basic + hra + da;

    cout << "HRA: " << hra << endl;
    cout << "DA: " << da << endl;
    cout << "Gross salary: " << gross;
    return 0;
}