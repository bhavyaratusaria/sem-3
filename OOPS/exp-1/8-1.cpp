#include <iostream>
using namespace std;

int main()
{
    float price, gstPer, amt, gst;

    cout << "Enter product price: ";
    cin >> price;
    cout << "Enter GST percentage: ";
    cin >> gstPer;

    gst = (price * gstPer) / 100.0;
    amt = price + gst;

    cout << "GST: " << gst << endl;
    cout << "Payable Amount: " << amt;
    return 0;
}