#include "contas.hpp"

Conta::Conta(string user, string psw):
       username(user), password(psw)
{
    this->setPriority();
}

string Conta::getUsername() const
{
    return username;
}

string Conta::getPassword() const
{
    return password;
}

bool Conta::getPriority() const
{
    return priority;
}

void Conta::setPriority()
{
    if(username.substr(username.length() - 4) == "adm" && password == "Senha_administracao123")
    {
        priority = true;
    }
    else
    {
        priority = false;
    }
}

void Conta::mudarSenha(string old_password, string new_password)
{
    if(old_password == password && new_password.length() > 5 && new_password.length() < 30)
    {
        password = new_password;
    }
    else if(old_password == password)
    {
        cout << "Senha invalida" << endl;
    }
    else
    {
        cout << "Senha incorreta" << endl;
    }
}