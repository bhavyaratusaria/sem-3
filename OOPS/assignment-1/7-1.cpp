#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter num: ";
    cin >> num;
    if (num == 0)
        cout << "Number is 0";
    else if ((num & 1) == 0)
        cout << "Number is odd";
    else
        cout << "Number is even";
    return 0;
}
