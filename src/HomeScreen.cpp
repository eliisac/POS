
#include <iostream>
#include "HomeScreen.h"
#include "CashierScreen.h"
#include "ManagerScreen.h"
using namespace std;

HomeScreen::HomeScreen(/* args */)
{

}
HomeScreen::~HomeScreen()
{

}
int HomeScreen::control()
{
    cout<< "------------------At homescreen-------------------" << endl;
    cout << "Press 1 to Login as Cashier " << endl;
    cout << "Press 2 to Login as Manager " << endl;
    char in = '0';
    
    cin.get(in);cin.ignore(numeric_limits<streamsize>::max(),'\n');
    switch(in)
    {
            case '1': return 1;break;
            case '2': return 2;break;
            default: return 0;

    }   
}

void HomeScreen::login()
{  
    
}

