#pragma once
#include "IUser.h"
#include "file.h"
#include <iostream>

class Manager : public  IUser
{
private:
    /* data */
    
public:
    Manager(/* args */);
    ~Manager();
    void Login();
    void showOrders();
};
