#include <iostream>
using namespace std;

int main()
{
    float h, w, bmi;
    cout << "Enter weight: ";
    cin >> w;
    cout << "Enter height in m: ";
    cin >> h;
    bmi = w / (h * h);

    cout << "Your BMI is: " << bmi << endl;
    cout << "category: ";
    if (bmi < 18.5)
        cout << "underweight";
    else if (bmi <= 24.9)
        cout << "normal weight";
    else if (bmi <= 29.9)
        cout << "overweight";
    else
        cout << "obese";
    return 0;
}
