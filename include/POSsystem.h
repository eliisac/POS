#pragma once
#include "Screen.h"

class POSsystem
{
private:
    Screen* screen;
public:
    POSsystem();
    ~POSsystem();
    void changeScreen(Screen* screen);
    int control();
    void login();
};





