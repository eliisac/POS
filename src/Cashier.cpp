
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
    cin >> in;cin.ignore(numeric_limits<streamsize>::max(),'\n');
    int orderId=0;
    switch(in)
    {
        case 1: cout << "Add items " << endl; 
                
                addRemoveOrder(); 
                break;
        case 2: cout << "Enter Order Id " << endl; 
                cin >> orderId; cin.ignore(numeric_limits<streamsize>::max(),'\n');
                recallOrder(orderId);
                break;
        default: cout << "Invalid Choice " << endl; 
    }

}
void Cashier::recallOrder(int orderId)
{
    file f;
    Order o = f.find(orderId);
    if(o.OrderId)
        o.showdetails();
}

void Cashier::addRemoveOrder()
{
    
    file orderId;
    int id=orderId.readid(1000)+1;
    Order o(id);
    addRemoveOrderLoop(o);
    orderId.write(o.OrderId); 
    file f;
    f.write(o);  
}

void Cashier::addRemoveOrderLoop( Order & o)
{
    int in=-1;
    addOrder(o);
    do
    {
        cout << "Press 1 to add more items to the Order " << endl;
        cout << "Press 2 to remove item from Order " << endl;
        cout << "Press 3 to checkout " << endl;
        in=-1;
        cin >> in; cin.ignore(numeric_limits<streamsize>::max(),'\n');
        switch(in)
        {
            case 1: cout << " Adding items " << endl;
                    addOrder(o);
                    break;
            case 2: cout << "Remove items " << endl; 
                    removeOrder(o); 
                    break;
            case 3: cout << "At Checkout " << endl; break;
            default: cout << "Invalid Choice " << endl; 
        }
    } while (in==1||in==2);
    
    
}

void Cashier::addOrder( Order & o) 
{
    
        int item=-1;
        cin >> item; cin.ignore(numeric_limits<streamsize>::max(),'\n');
        while(item>0)
        {
            cout << "Item not found in warehouse, please enter the price " << endl;
            double amount=0;
            cin >> amount; cin.ignore(numeric_limits<streamsize>::max(),'\n');
            Item newItem={item,amount};
            cout << "Enter the quantity" << endl;
            int qty=1;
            cin >> qty; cin.ignore(numeric_limits<streamsize>::max(),'\n');
            
            o.addItem(newItem,qty);
            cout << "Enter next item or press 0 to complete the order " << endl; 
            cin >> item; cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        o.showdetails();   
        
}

void Cashier::removeOrder(Order & o)
{
    
        int itemNo=-1;
        cin >> itemNo;
        while(itemNo>0)
        {
            o.deleteItem(itemNo);
            cout << "Enter next item to be removed or press 0 to complete the order " << endl; 
            cin >> itemNo; cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        o.showdetails();   
}
