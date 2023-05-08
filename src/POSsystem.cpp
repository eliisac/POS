
#include "POSsystem.h"
#include "HomeScreen.h"

POSsystem::POSsystem()
{
    this->screen=new HomeScreen();
}


POSsystem::~POSsystem()
{
    delete screen;
}

void POSsystem::changeScreen(Screen* screen)
{
    this->screen=screen;
}

int POSsystem::control()
{
    HomeScreen h;
    return (h.control());
}

void POSsystem::login()
{
    screen->login();
}
