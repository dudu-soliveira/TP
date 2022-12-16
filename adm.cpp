#include "adm.hpp"

Adm::Adm(string user, string psw, string nm,
         string eml, string jb, double phone):
        
    Conta(user, psw), name(nm), email(eml),
    job(jb), phone_number(phone)
{
    this->setPriority();
}
void Adm::adicionarProduto(Produto* prod)
{
    if(this->job == "")
}