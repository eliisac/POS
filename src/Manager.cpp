
#include "Manager.h"
#include <iostream>

Manager::Manager(/* args */)
{
}

Manager::~Manager()
{
}
void Manager::Login()
{
    using namespace std;
    cout << "Login as a manager " << endl;
    cout << "Press 1 to show all orders " << endl;
    int in=-1;
    cin >> in;
    switch(in)
    {
        case 1: cout << "All Orders " << endl; 
                showOrders(); 
                break;
        default: cout << "Invalid Choice " << endl; 
    }
}

void Manager::showOrders()
{
    file f;
    list<Order> allOrders = f.read();
    int c=1;
    if(allOrders.empty())
    {
        cout << "No orders" << endl;
    }
    else
    {
        for(list<Order> :: iterator itr=allOrders.begin();itr!=allOrders.end();++itr)
        {
            //cout << c << endl;
            cout << endl << "============================================" << endl;
    cout << "Order No:" << itr->OrderId << endl;
    char* dt = ctime(&itr->OrderAddDatetime );
    cout << "Order Date:" << dt << endl << endl;
    cout << "items" << "  " << "price"<< " " << "quantity" << " " << "total" << endl;
    for(vector < pair <Item,int> >:: iterator itrv=itr->itemList.begin();itrv!=itr->itemList.end();++itrv)
    {
        cout << itrv->first.barCode << "  " << itrv->first.price << " " << itrv->second << " " <<itrv->second*itrv->first.price  << endl;
    }
    cout << endl << "Total Price: " << itr->totalPrice << endl;
    cout << "============================================" << endl << endl;
            ++c;
        }
    }

}

