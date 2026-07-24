#include <iostream>
using namespace std;
// wac++p to dynamically allocate memory for an arry of n integers. Accept the elements, calculate their sum and average, display the results, and release the memory using delete.

int main()
{
    int *ptr = new int[5];
    int i, sum = 0;

    cout << "Enter elements for array: ";
    for (i = 0; i < 5; i++)
    {
        cin >> ptr[i];
    }

    for (i = 0; i < 5; i++)
    {
        sum += ptr[i];
    }
    float avg = sum / 5.0;

    cout << "Sum= " << sum << endl;
    cout << "Average= " << avg;
    delete[] ptr;
    return 0;
}