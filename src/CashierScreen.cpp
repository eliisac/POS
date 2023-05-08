#include <iostream>
#include "CashierScreen.h"
#include "Cashier.h"
using namespace std;

CashierScreen::CashierScreen()
{

}

CashierScreen::~CashierScreen()
{

}
void CashierScreen::login()
{
    
    Cashier cashier;
    cashier.Login();
}
