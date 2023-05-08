#pragma once
#include <iostream>
#include "Screen.h"

class CashierScreen: public Screen
{
private:
    /* data */
public:
    CashierScreen(/* args */);
    ~CashierScreen();
    void login();
};