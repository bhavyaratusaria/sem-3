#include <iostream>
using namespace std;

class Fact
{
    int n, i;

public:
    void accept();
    void display();
    void fact();
} f1;

inline void Fact::accept()
{
    cout << "Enter number: ";
    cin >> n;
}
inline void Fact::fact()
{
    for (i = n - 1; i > 0; i--)
    {
        n *= i;
    }
}
inline void Fact::display()
{
    cout << "Answer: " << n;
}

int main()
{
    f1.accept();
    f1.fact();
    f1.display();
    return 0;
}