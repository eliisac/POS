#pragma once
#include "IUser.h"
#include "Order.h"
#include "file.h"

class Cashier:public  IUser
{
private:
    /* data */
public:
    Cashier(/* args */);
    ~Cashier();
    void Login();
    void addOrder( Order & o);
    void removeOrder( Order & o);
    void addRemoveOrder();
    void addRemoveOrderLoop( Order & o);
    void recallOrder(int orderId);
};
