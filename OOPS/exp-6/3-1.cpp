#include <iostream>
using namespace std;

class second;
class first
{
    int n1;

public:
    void accept();
    friend void display(first f, second s);
} f1;

class second
{
    int n2;

public:
    void accept();
    friend void display(first f, second s);
} s1;

void first::accept()
{
    cout << "Enter first no.: ";
    cin >> n1;
}
void second::accept()
{
    cout << "Enter second no.: ";
    cin >> n2;
}

void display(first f, second s)
{
    cout << "Average = " << (f.n1 + s.n2) / 2;
}

int main()
{
    f1.accept();
    s1.accept();
    display(f1, s1);
    return 0;
}
