#pragma once
#include <iostream>
#include "Manager.h"
#include "Cashier.h"
#include "Screen.h"

class HomeScreen:public Screen
{
private:
    /* data */
public:
    HomeScreen(/* args */);
    ~HomeScreen();
    int control();
    void login();
};