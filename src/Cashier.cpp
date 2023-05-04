
#include "Cashier.h"
#include <iostream>

Cashier::Cashier()
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
        case 1: cout << "Add items " << endl; 
                
                addRemoveOrder(); 
                break;
        case 2: cout << "Enter Order Id " << endl; break;
        default: cout << "Invalid Choice " << endl; 
    }

}

void Cashier::addRemoveOrder()
{
    
    file orderId;
    int id=orderId.readid(1000)+1;
    Order o(id);
    addOrder(o);
    cout << "Press 1 to remove item from Order " << endl;
    cout << "Press 2 to checkout " << endl;
    int in=-1;
    cin >> in;
    switch(in)
    {
        case 1: cout << "Remove items " << endl; 
                removeOrder(o); 
        case 2: cout << "At Checkout " << endl; break;
        default: cout << "Invalid Choice " << endl; 
    }
    orderId.write(o.OrderId);
}

void Cashier::addOrder( Order & o)
{
    
        int item=-1;
        cin >> item;
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
            cout << "Enter next item or press 0 to complete the order " << endl; 
            cin >> item;
        }
        o.showdetails();   
        file f;
        f.write(o);
}

void Cashier::removeOrder(Order & o)
{
    
        int itemNo=-1;
        cin >> itemNo;
        while(itemNo>0)
        {
            o.deleteItem(itemNo);
            cout << "Enter next item to be removed or press 0 to complete the order " << endl; 
            cin >> itemNo;
        }
        o.showdetails();   
}
