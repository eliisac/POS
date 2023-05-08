#pragma once
#include <iostream>
#include "Manager.h"
#include "Cashier.h"
#include "Screen.h"

class ManagerScreen: public Screen
{
private:
    /* data */
public:
    ManagerScreen(/* args */);
    ~ManagerScreen();
    void login();
};