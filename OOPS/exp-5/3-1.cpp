#include <iostream>
using namespace std;
// 3. Write an inline function to calculate the area of a circle.
class circle
{
    int r;
    const float PI = 3.1415;

public:
    void accept();
    void display();
} c1;

inline void circle::accept()
{
    cout << "Enter radius: ";
    cin >> r;
}
inline void circle::display()
{
    cout << "Area of circle: " << PI * r * r;
}
int main()
{
    c1.accept();
    c1.display();
    return 0;
}
