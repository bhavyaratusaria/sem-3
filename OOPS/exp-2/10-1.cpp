#include <iostream>
#include <iomanip>
using namespace std;
// WAC++P to display marks of five subjects in a neatly aligned table using the different manipulators.

int main()
{
    int i, marks[5];
    string sub[5];

    for (i = 0; i < 5; i++)
    {
        cout << "Enter Subject Name: ";
        cin >> sub[i];
        cout << "Enter its marks: ";
        cin >> marks[i];
    }
    cout << setfill('-') << setw(35) << "" << endl;
    cout << setfill(' ') << left << setw(25) << "Subject";
    cout << right << setw(10) << "Marks" << endl;
    cout << setfill('-') << setw(35) << "" << endl;

    for (i = 0; i < 5; i++)
    {
        cout << setfill(' ') << left << setw(25) << sub[i];
        cout << right << setw(10) << marks[i] << endl;
    }

    cout << setfill('-') << setw(35) << "";
    return 0;
}