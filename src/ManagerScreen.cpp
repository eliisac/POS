#include <iostream>
#include "ManagerScreen.h"
#include "Manager.h"
using namespace std;

ManagerScreen::ManagerScreen()
{

}

ManagerScreen::~ManagerScreen()
{

}
void ManagerScreen::login()
{
    
    Manager manager;
    manager.Login();
}