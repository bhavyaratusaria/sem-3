#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n1, n2, n3, n4, sum, diff, prod, rem, power;
    double fact, sqroot, quot;
    cout << "Scientific Calculator" << endl;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;
    cout << "Enter number and power: ";
    cin >> n3 >> n4;

    sum = n1 + n2;
    diff = n1 - n2;
    prod = n1 * n2;
    quot = n1 / n2;
    rem = n1 % n2;
    power = pow(n3, n4);
    fact = tgamma(n3 + 1);
    sqroot = sqrt(n3);

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;
    cout << "Quotient: " << quot << endl;
    cout << "Remainder: " << rem << endl;
    cout << "Power: " << power << endl;
    cout << "Factorial: " << fact << endl;
    cout << "Square root: " << sqroot;
    return 0;
}