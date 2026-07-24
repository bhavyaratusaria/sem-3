#include <iostream>
using namespace std;

int main()
{
    int km, m, cm, mm;
    cout << "Enter distance in kilometers: ";
    cin >> km;
    m = km * 1000;
    cm = m * 100;
    mm = cm * 10;

    cout << "Meters: " << m << " m" << endl;
    cout << "Centimeters: " << cm << " cm" << endl;
    cout << "Millimeters: " << mm << " mm";
    return 0;
}