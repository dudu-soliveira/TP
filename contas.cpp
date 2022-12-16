#include "contas.hpp"

Conta::Conta(string user, string psw):
       username(user), password(psw) 
{}
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
