#include "pessoal.hpp"

Pessoal::Pessoal(string user, string psw, string nm, string adr,
                 string eml, int ag, double id, double phone):

        Conta(user,psw), name(nm), address(adr), email(eml), 
        age(ag), cpf(id), phone_number(phone), saldo(0)
{
    setPriority();
}

void Pessoal::mudarTelefone(double new_phone)
{
    phone_number = new_phone;
}

void Pessoal::mudarSenha(string old_password, string new_password)
{
    if(old_password == password && new_password.length() > 5 && new_password.length() < 30)
    {
        password = new_password;
    }
    else if(old_password == password)
    {
        cout << "senha invalida" << endl;
    }
    else
    {
        cout << "senha incorreta" << endl;
    }
}

void Pessoal::mudarEndereco(string new_address)
{
    address = new_address;
}

void Pessoal::adicionarCartao(Cartao new_card)
{
    cartoes.insert(pair<string,Cartao>(new_card.getApelido(), new_card));
}

void Pessoal::adicionarSaldo(string card, float amount)
{
    if(cartoes.find(card) != cartoes.end())
    {
        saldo += amount;
    }
    else
    {
        cout << "cartao nao existente" << endl;
    }
}