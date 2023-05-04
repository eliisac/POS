#pragma once
#include <ctime>
#include <vector>
#include "Item.h"

using namespace std;

struct Order
{

    
    Order(int num);
    ~Order();
    void addItem(Item item, int qty);
    void deleteItem(int itemNo);
    void showdetails();
    int getOrderId();

    int OrderId;
    time_t OrderAddDatetime;
    time_t OrderUpdateDatetime;
    vector <pair <Item,int> > itemList;
    double totalPrice;

};

