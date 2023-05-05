#pragma once
#include <fstream>
#include "Order.h"
#include <list>


class file
{
private:
    ofstream outfile;
    ifstream infile;
    fstream iofile;
public:
    file(/* args */);
    ~file();
    void write(Order & o);
    void write(int lastorderid);
    list<Order> read();
    int readid(int id=1000);
    Order find(int OrderId);
};

