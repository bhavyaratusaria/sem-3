#include <iostream>
using namespace std;
// Create a class Product to store product information and display the details using functions defined outside the class.

class Product
{
    int pno, cost;

public:
    void accept();
    void display();
} p1;

void Product::accept()
{
    cout << "Enter product no.: ";
    cin >> pno;
    cout << "Enter cost: ";
    cin >> cost;
}
void Product::display()
{
    cout << "Product No.: " << pno << endl;
    cout << "Cost: " << cost << endl;
}

int main()
{
    p1.accept();
    p1.display();
    return 0;
}