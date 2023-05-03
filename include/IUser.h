#pragma once

class IUser
{
public:
    IUser(/* args */);
    ~IUser();
    virtual void Login() = 0 ;

};

IUser::IUser(/* args */)
{
}

IUser::~IUser()
{
}

