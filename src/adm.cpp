#include "adm.hpp"

Adm::Adm(string user, string psw, string nm,
         string eml, string jb, string phone):
        
    username(user), password(psw), name(nm), email(eml), job(jb), phone_number(phone), priority(1)
{}

string Adm::getUsername() const
{
    return username;
}

string Adm::getPassword() const
{
    return password;
}

string Adm::getName() const
{
    return name;
}

void Adm::mudarSenha(string new_password)
{
    password = new_password;
}

string Adm::descricao()
{
    string desc = "Usuario: " + username;
    desc += "\nSenha: " + password + "\nNome: " + name;
    desc += "\nE-mail: " + email + "\nCelular " + phone_number;
    desc += "\nProfissao: " + job + "\n";
    return desc;
}