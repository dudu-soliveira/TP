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
    string getUsername() const;
    string getPassword() const;
    bool getPriority() const;
    void setPriority();
    void mudarSenha(string old_password, string new_password);
    virtual string descricao() = 0;
    virtual ~Conta() = default;
};

#endif