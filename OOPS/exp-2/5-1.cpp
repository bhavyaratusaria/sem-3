#include <iostream>
using namespace std;
// Create two namespaces, Physics and Chemistry, each containing the same variable name for accessing subject. Use the scope resolution operator to call the appropriate data member from each namespace.
namespace Physics
{
    string sub = "Physics";
}
namespace Chemistry
{
    string sub = "Chemistry";
}

int main()
{
    cout << "Subject 1: " << Physics::sub << endl;
    cout << "Subject 2: " << Chemistry::sub;
    return 0;
}