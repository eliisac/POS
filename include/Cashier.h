#pragma once
#include "IUser.h"
#include <iostream>
#include <Order.h>
class Cashier:public IUser
{
private:
    /* data */
public:
    Cashier(/* args */);
    ~Cashier();
    void Login();
    void addOrder();
};

Cashier::Cashier(/* args */)
{
}

Cashier::~Cashier()
{
}

void Cashier::Login()
{
    using namespace std;
    cout << "Login as a Cashier " << endl;
    cout << "Press 1 to Create new order " << endl;
    cout << "Press 2 to Recall an order" << endl;
    //cout << "Press 3 to go to previous screen" << endl;
    int in=-1;
    cin >> in;
    switch(in)
    {
        case 1: cout << "Add items " << endl; addOrder(); break;
        case 2: cout << "Enter Order Id " << endl; break;
        default: cout << "Invalid Choice " << endl; 
    }
}

void Cashier::addOrder()
{
    
        int item=-1;
        cin >> item;
        Order o;
        while(item>0)
        {
            cout << "Item not found in warehouse, please enter the price " << endl;
            double amount=0;
            cin >> amount;
            Item newItem={item,amount};
            cout << "Enter the quantity" << endl;
            int qty=1;
            cin >> qty;
            
            o.addItem(newItem,qty);
            cout << "Add next item press 0 to complete the order " << endl; 
            cin >> item;
        }
        o.showdetails();
    
}
