#pragma once
#include <fstream>
#include "Order.h"
#include <list>


class file
{
private:
    ofstream outfile;
    ifstream infile;
public:
    file(/* args */);
    ~file();
    void write(Order & o);
    void write(int lastorderid);
    list<Order> read();
    int readid(int id=1000);
};

