#include <iostream>
using namespace std;

int main()
{
    int marks[6], total = 0, i;
    float per, avg;

    cout << "Enter marks for 6 subjects:";
    for (i = 0; i < 6; i++)
    {
        cin >> marks[i];
    }

    for (i = 0; i < 6; i++)
    {
        total += marks[i];
    }
    per = (total / 600.0) * 100;
    avg = total / 6.0;

    cout << "Total Marks: " << total << endl;
    cout << "Average: " << avg << endl;
    cout << "Percentage: " << per << "%" << endl;

    cout << "Grade: ";
    if (per >= 80)
        cout << "A";
    else if (per >= 60)
        cout << "B";
    else if (per >= 40)
        cout << "C";
    else
        cout << "F -> Failed";
    return 0;
}