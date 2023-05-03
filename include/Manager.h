#pragma once

#include "IUser.h"
#include <iostream>

class Manager : public IUser
{
private:
    /* data */
    
public:
    Manager(/* args */);
    ~Manager();
    void Login();
};

Manager::Manager(/* args */)
{
}

Manager::~Manager()
{
}

void Manager::Login()
{
    std::cout << "Login as a manager " << std::endl;
}

