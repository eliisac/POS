#include <iostream>


int main(int argc, char* argv[])
{
    using namespace std;
    cout << "Press 1 to Login as Cashier " << endl;
    cout << "Press 2 to Login as Manager " << endl;
    int in=-1;
    cin >> in;
    switch(in)
    {
        case 1: cout << "Cashier selected" << endl;break;
        case 2: cout << "Manager selected" << endl;break;
        default: cout << "Invalid Choice" << endl;

    }
    return 0;
}