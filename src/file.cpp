
#include "file.h"
#include <iostream>


using namespace std;

file::file(/* args */)
{
}

file::~file()
{
}
void file::write(Order & o)
{
    outfile.open("OrdersHistory.bin", ios::binary | ios::app);
    if(outfile)
    {
        outfile.write(reinterpret_cast<const char*>(&o.OrderId), sizeof(int));

        outfile.write(reinterpret_cast<const char*>(&o.OrderAddDatetime), sizeof(time_t));
        outfile.write(reinterpret_cast<const char*>(&o.OrderUpdateDatetime), sizeof(time_t));

        size_t sizeVector=o.itemList.size();
        outfile.write(reinterpret_cast<const char*>(&sizeVector), sizeof(size_t));
        for(int i=0;i<sizeVector;++i)
        {
            outfile.write(reinterpret_cast<const char*>(&o.itemList[i].first.barCode), sizeof(int));
            outfile.write(reinterpret_cast<const char*>(&o.itemList[i].first.price), sizeof(double));
            outfile.write(reinterpret_cast<const char*>(&o.itemList[i].second), sizeof(int));
        }
        
        outfile.write(reinterpret_cast<const char*>(&o.totalPrice), sizeof(double));
        char filestage = 'i';
        outfile.write(reinterpret_cast<const char*>(&filestage), sizeof(char));

        outfile.close();
    }
    else
    {
        cout << "File cannot be opened for writing" << endl;
    }
}

list<Order> file::read()
{
    list<Order> orderList;
    infile.open("OrdersHistory.bin", ios::binary);
    Order newOrder(0);
    if (infile)
    {
        infile.seekg(0,ios::end);
        int endpos=infile.tellg();
        infile.seekg(0,ios::beg);
    while (infile.tellg()!=-1&&infile.tellg()<endpos)
    {

        infile.read(reinterpret_cast<char*>(&newOrder.OrderId), sizeof(int));

        infile.read(reinterpret_cast<char*>(&newOrder.OrderAddDatetime), sizeof(time_t));
        infile.read(reinterpret_cast<char*>(&newOrder.OrderUpdateDatetime), sizeof(time_t));

        size_t sizeVector=0;
        infile.read(reinterpret_cast<char*>(&sizeVector), sizeof(size_t));
        newOrder.itemList.resize(sizeVector);
       for(int i=0;i<sizeVector;++i)
        {
            infile.read(reinterpret_cast< char*>(&newOrder.itemList[i].first.barCode), sizeof(int));
            infile.read(reinterpret_cast< char*>(&newOrder.itemList[i].first.price), sizeof(double));
            infile.read(reinterpret_cast< char*>(&newOrder.itemList[i].second), sizeof(int));
        }
        
        infile.read(reinterpret_cast< char*>(&newOrder.totalPrice), sizeof(double));
        char filestage = 'i';
        infile.read(reinterpret_cast< char*>(&filestage), sizeof(char));
        if(filestage=='i')
            orderList.push_back(newOrder);
        
      
    }
    infile.close();
}
    return orderList;
}



void file::write(int lastorderid)
{
    outfile.open("OrdersId.bin", ios::binary);
    if(outfile)
    {
        outfile.write(reinterpret_cast<const char*>(&lastorderid), sizeof(int));
        outfile.close();
    }
    else
    {
        cout << "File cannot be opened for writing" << endl;
    }
}

int file::readid(int id)
{
    infile.open("OrdersId.bin", ios::binary);
    
    if (infile)
    {
        infile.read(reinterpret_cast<char*>(&id), sizeof(int));
        infile.close();
      
    }
    return id;
    
}

Order file::find(int orderId)
{
    iofile.open("OrdersHistory.bin", ios::binary|ios::in | ios::out);
    Order newOrder(0);
    int flag=-1;
    if (iofile)
    {
        iofile.seekg(0,ios::end);
        int endpos=iofile.tellg();
        iofile.seekg(0,ios::beg);
        while (iofile.tellg()!=-1&&iofile.tellg()<endpos)
        {

        iofile.read(reinterpret_cast<char*>(&newOrder.OrderId), sizeof(int));
        iofile.read(reinterpret_cast<char*>(&newOrder.OrderAddDatetime), sizeof(time_t));
        iofile.read(reinterpret_cast<char*>(&newOrder.OrderUpdateDatetime), sizeof(time_t));

        size_t sizeVector=0;
        iofile.read(reinterpret_cast<char*>(&sizeVector), sizeof(size_t));
        newOrder.itemList.resize(sizeVector);
       for(int i=0;i<sizeVector;++i)
        {
            iofile.read(reinterpret_cast< char*>(&newOrder.itemList[i].first.barCode), sizeof(int));
            iofile.read(reinterpret_cast< char*>(&newOrder.itemList[i].first.price), sizeof(double));
            iofile.read(reinterpret_cast< char*>(&newOrder.itemList[i].second), sizeof(int));
        }
        
        iofile.read(reinterpret_cast< char*>(&newOrder.totalPrice), sizeof(double));
        char filestage = 'i';
        iofile.read(reinterpret_cast< char*>(&filestage), sizeof(char));
        if(filestage!='r')
        {    
            if(newOrder.OrderId==orderId)
            {
                filestage='r';
                cout << "Match found" << endl;
                flag=1;
                int newpos=(iofile.tellg() );
                iofile.seekp(newpos-1,ios::beg);
                iofile.seekg(newpos-1,ios::beg);
                iofile.write(reinterpret_cast<const char*>(&filestage), sizeof(char));
                break;
            }
        }
      
    }
    iofile.close();
    }
    else
    {
        cout << "Cannot open file!" << endl;
    }
    if(flag==1) 
        return newOrder;
    else
    {
        cout << "No such Order" << endl;
        Order newo(0);
        return newo;
    }
}

/*
Order file::find(int orderId)
{
    iofile.open("OrdersHistory.bin", ios::binary| ios::app);
    Order newOrder(0);
    int flag=-1;
    if (iofile)
    {
        iofile.seekg(0,ios::end);
        int endpos=iofile.tellg();
        iofile.seekg(0,ios::beg);
        while (iofile.tellg()!=-1&&iofile.tellg()<endpos)
        {

        iofile.read(reinterpret_cast<char*>(&newOrder.OrderId), sizeof(int));
        iofile.read(reinterpret_cast<char*>(&newOrder.OrderAddDatetime), sizeof(time_t));
        iofile.read(reinterpret_cast<char*>(&newOrder.OrderUpdateDatetime), sizeof(time_t));

        size_t sizeVector=0;
        iofile.read(reinterpret_cast<char*>(&sizeVector), sizeof(size_t));
        newOrder.itemList.resize(sizeVector);
       for(int i=0;i<sizeVector;++i)
        {
            iofile.read(reinterpret_cast< char*>(&newOrder.itemList[i].first.barCode), sizeof(int));
            iofile.read(reinterpret_cast< char*>(&newOrder.itemList[i].first.price), sizeof(double));
            iofile.read(reinterpret_cast< char*>(&newOrder.itemList[i].second), sizeof(int));
        }
        
        iofile.read(reinterpret_cast< char*>(&newOrder.totalPrice), sizeof(double));
        char filestage = 'i';
        iofile.read(reinterpret_cast< char*>(&filestage), sizeof(char));
        cout << filestage << endl;
        if(filestage!='r')
        {    
            if(newOrder.OrderId==orderId)
            {
                filestage='r';
                cout << "Match found" << endl;
                iofile.seekg(-1,ios::cur);
                iofile.write(reinterpret_cast<const char*>(&filestage), sizeof(char));
                flag=1;
                break;
            }
        }
      
    }
    iofile.close();
    }
    else
    {
        cout << "Cannot open file!" << endl;
    }
    if(flag==1) 
        return newOrder;
    else
    {
        cout << "No such Order" << endl;
        Order newo(0);
        return newo;
    }
}


*/