#include <iostream>
using namespace std;
// Develop a program to store and display library book records.

class Book
{
    int id;
    string name, author;

public:
    void accept()
    {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Author: ";
        cin >> author;
    }
    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Author: " << author << endl;
    }
} b[5];
int main()
{
    int i;
    cout << "Enter Details for 5 Books: ";
    for (i = 0; i < 5; i++)
    {
        cout << endl
             << "Book " << i + 1 << endl;
        b[i].accept();
    }
    cout << endl;
    cout << "Library Book Records: " << endl;
    for (i = 0; i < 5; i++)
    {
        b[i].display();
        cout << endl;
    }
    return 0;
}