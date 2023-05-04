#include <iomanip>
#include <iostream>
#include "Order.h"

using namespace std;

Order::Order(int num)
{
    
    this->OrderAddDatetime=time(0);
    this->OrderUpdateDatetime=time(0);
    this->OrderId=num;
    this->totalPrice=0;
}

Order::~Order()
{
}



void Order::addItem(Item item, int qty=1) 
{
    pair <Item,int> newItem;
    newItem.first=item;
    newItem.second=qty;
    this->itemList.push_back(newItem);
    this->totalPrice+=(item.price*qty);
    this->OrderUpdateDatetime=time(0);
}

void Order::deleteItem(int itemNo) 
{
   int noOfItems=this->itemList.size();
   if(noOfItems<itemNo)
   {
        cout << "No such item in the list " << endl;
        return;
   }
   else
   {
        pair <Item,int> curentItem = this->itemList[itemNo-1];
        int qty=1;
        int no=curentItem.second;
        if(no>1)
        {
            cout << "How many items should be removed, Total available is:" << no << endl;
            cin >> qty;
        }
        //c
        if(curentItem.second-qty<=0)
        {
            this->totalPrice-=(curentItem.second*curentItem.first.price);
            vector < pair <Item,int> > :: iterator itr=this->itemList.begin()+itemNo-1;
            this->itemList.erase(itr);
        }
        else
        {
            curentItem.second-=qty;
            this->itemList[itemNo-1]=curentItem;
            this->totalPrice-=(qty*curentItem.first.price);
        }   
   }  
}

void Order::showdetails()
{
    cout << endl << "============================================" << endl;
    cout << "Order No:" << setw(5) << this->OrderId << endl;
    char* dt = ctime(&this->OrderAddDatetime );
    cout << "Order Date:" << setw(5) << dt << endl << endl;
    cout << "items" << "  " << "price"<< " " << "quantity" << " " << "total" << endl;
    for(vector < pair <Item,int> >:: iterator itr=this->itemList.begin();itr!=this->itemList.end();++itr)
    {
        cout << itr->first.barCode << setw(15)  << itr->first.price << setw(15) << itr->second << setw(10) <<itr->second*itr->first.price  << endl;
    }
    cout << endl << "Total Price:" << setw(5) << this->totalPrice << endl;
    cout << "============================================" << endl << endl;
}



