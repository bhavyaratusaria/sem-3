#include <iostream>
using namespace std;
// 8. Demonstrate the concept of static member function using sample program.

class Square
{
    static int side;

public:
    static void Area()
    {
        cout << "Area of square: " << side * side;
    }
};
int Square::side = 10;

int main()
{
    Square::Area();
    return 0;
}