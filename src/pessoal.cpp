#include "pessoal.hpp"

Pessoal::Pessoal(string user, string psw, string nm, string adr,
                 string eml, int ag, long long int id, long long int phone):

        username(user), password(psw), name(nm), address(adr), email(eml), 
        age(ag), cpf(id), phone_number(phone), priority(0)
{}

string Pessoal::getUsername() const
{
    return username;
}

string Pessoal::getPassword() const
{
    return password;
}

string Pessoal::getName() const
{
    return name;
}

string Pessoal::getEndereco() const
{
    return address;
}

void Pessoal::mudarSenha(string new_password)
{
    password = new_password;
}

void Pessoal::mudarEndereco(string new_address)
{
    address = new_address;
}

void Pessoal::mudarTelefone(long long int new_phone)
{
    phone_number = new_phone;
}

void Pessoal::adicionarCartao(Cartao new_card)
{
    cartoes.insert(pair<string,Cartao>(new_card.getApelido(), new_card));
}

string Pessoal::descricao()
{
    string desc = "Usuario: " + username;
    desc += "\nSenha: " + password + "\nNome: " + name;
    desc += "\nIdade: " + to_string(age) + "\nCPF: " + to_string(cpf);
    desc += "\nE-mail: " + email + "\nCelular: " + to_string(phone_number);
    desc += "\nEndereco: " + address;
    if(cartoes.empty() == false)
    {
        desc += "\nCartoes:\n";
        for(auto itr: cartoes)
        {
            desc += itr.second.descricao() + "\n";
        }
    }
    if(cartoes.empty() == true)
    {
    desc += "\n";
    }
    return desc;
}