#include <iostream>
using namespace std;

class Car
{
public:
    string brand, model;
    int year;

    void display()
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
} C1, C2;

int main()
{
    cout << "Car-1:" << endl;
    cout << "Enter brand: ";
    cin >> C1.brand;
    cout << "Enter model: ";
    cin >> C1.model;
    cout << "Enter year: ";
    cin >> C1.year;

    cout << "\nCar-2:" << endl;
    cout << "Enter brand: ";
    cin >> C2.brand;
    cout << "Enter model: ";
    cin >> C2.model;
    cout << "Enter year: ";
    cin >> C2.year;

    cout << endl
         << "Car-1 Details:" << endl;
    C1.display();
    cout << endl
         << "Car-2 Details:" << endl;
    C2.display();
    return 0;
}
