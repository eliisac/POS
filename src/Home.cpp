
#include <iostream>
#include "Home.h"
using namespace std;


Home::Home()
{

}

Home::~Home()
{

}
void Home::HomeScreen()
{
    
    cout << "Press 1 to Login as Cashier " << endl;
    cout << "Press 2 to Login as Manager " << endl;
    int in=-1;
    cin >> in;
    
    Cashier cashier; 
    Manager manager; 

    switch(in)
    {
        case 1: cashier.Login();break;
        case 2:  manager.Login();break;
        default: cout << "Invalid Choice" << endl;

    }
}