#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include "Item.h"

using namespace std;

class Order
{
private:
    
    int OrderId;
    time_t OrderAddDatetime;
    time_t OrderUpdateDatetime;
    vector <pair <Item,int> > itemList;
    double totalPrice;
public:
    static int num;
    Order(/* args */);
    ~Order();
    void addItem(Item item, int qty);
    void deleteItem(int itemNo);
    void showdetails();
};

Order::Order(/* args */)
{
    Order::num++;
    this->OrderAddDatetime=time(0);
    this->OrderId=num;
    this->totalPrice=0;
    
}

Order::~Order()
{
}

int Order::num=1000;

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
   int noOfItems=itemList.size();
   if(noOfItems<itemNo)
   {
        cout << "No such item in the list " << endl;
        return;
   }
   else
   {
        pair <Item,int> curentItem = itemList[itemNo-1];
        int qty=1;
        int no=curentItem.second;
        if(no>1)
        {
            cout << "How many items should be removed, Total available is:" << no << endl;
            cin >> qty;
        }
        curentItem.second-=qty;
        if(curentItem.second<=0)
        {
            vector < pair <Item,int> > :: iterator itr=itemList.begin()+itemNo-1;
            itemList.erase(itr);
        }    
   }  
}

void Order::showdetails()
{
    cout << "Order No:" << this->OrderId << endl;
    cout << "Order Date:" << this->OrderAddDatetime << endl;
    cout << "items" << "  " << "price"<< " " << "quantity" << " " << "total" << endl;
    for(vector < pair <Item,int> >:: iterator itr=this->itemList.begin();itr!=this->itemList.end();++itr)
    {
        cout << itr->first.barCode << "  " << itr->first.price << " " << itr->second << " " <<itr->second*itr->first.price  << endl;
    }
    cout << "Total Price: " << this->totalPrice << endl;
}

