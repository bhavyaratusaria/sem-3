#include <iostream>
using namespace std;
// access global variable using scope resolution operator
int x = 100;
int main()
{
    int x = 50;
    cout << "local variable: " << x << endl;
    cout << "global variable: " << ::x;
    return 0;
}