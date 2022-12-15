#ifndef CONTA
#define CONTA

#include <string>
#include <iostream>

using namespace std;

class Conta
{
    protected:

    string username, password;
    bool priority;

    public:

    Conta(string user, string psw);
    void setPriority();
};

#endif
