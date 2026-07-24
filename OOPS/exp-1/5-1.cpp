#include <iostream>
using namespace std;

int main()
{
    int a, b, c, x, ans;

    cout << "Quadratic Equation Evaluator:" << endl;
    cout << "Enter values:-" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    cout << "Enter value of x: ";
    cin >> x;

    ans = (a * x * x) + (b * x) + c;
    cout << "Answer is: " << ans;
    return 0;
}