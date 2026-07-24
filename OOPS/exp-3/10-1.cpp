#include <iostream>
using namespace std;
/* Write a c++ code to create a class staff having data members as id and post.
 Accept and display data for 2 staff. Write member function definition inside the class. */

class staff
{
    int id;
    string post;

public:
    void accept()
    {
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter post: ";
        cin >> post;
    }
    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Post: " << post << endl;
    }
} s1, s2;

int main()
{
    s1.accept();
    s2.accept();
    s1.display();
    s2.display();
    return 0;
}