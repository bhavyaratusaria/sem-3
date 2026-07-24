#include <iostream>
using namespace std;

// use memory operators new and delete
int main()
{
    int *ptr = new int;
    *ptr = 42;
    cout << "ptr= " << *ptr;
    delete ptr;
    return 0;
}