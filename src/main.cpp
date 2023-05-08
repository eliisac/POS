#include "HomeScreen.h"
#include "Screen.h"
#include "POSsystem.h"
#include "CashierScreen.h"
#include "ManagerScreen.h"

int main(int argc, char* argv[])
{
    POSsystem pos;
    int choice=1;
    int val=-1;
    while(choice==1)
    {
        
        try
        {
            val=pos.control();
            switch(val)
            {
                case 1: pos.changeScreen(new CashierScreen()); pos.login(); break;
                case 2:  pos.changeScreen(new ManagerScreen()); pos.login(); break;
                default: cout << "Invalid Choice" << endl; 

            }
            

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        choice=0;
        cout << "Press 1 to go to Homescreen" << endl;
        cin >> choice; cin.ignore();
        
    }
    return 0;
}