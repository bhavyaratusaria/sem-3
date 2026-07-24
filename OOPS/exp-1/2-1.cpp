#include <iostream>
using namespace std;

int main()
{
    int s1, s2, s3, s4, s5;
    float total, per;
    cout << "Enter marks for 5 subjects: ";
    cin >> s1 >> s2 >> s3 >> s4 >> s5;

    total = s1 + s2 + s3 + s4 + s5;
    per = (total / 500.0) * 100;
    cout << "Total Marks: " << total << endl;
    cout << "Percentage: " << per << "%" << endl;

    cout << "Grade: ";
    if (per >= 80)
        cout << "A";
    else if (per >= 60)
        cout << "B";
    else if (per >= 40)
        cout << "C";
    else
        cout << "F";
    return 0;
}