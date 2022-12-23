#ifndef PESSOAL
#define PESSOAL

#include <map>
#include <string>
#include <iostream>

#include "cartoes.hpp"

class Pessoal
{
    string username, password, name, address, email;
    int age;
    long long int cpf, phone_number;
    bool priority;
    map<string,Cartao> cartoes;

    public:

    Pessoal(string user, string psw, string nm, string adr,
            string eml, int ag, long long int id, long long int phone);

    string getUsername() const;
    string getPassword() const;
    string getName() const;
    string getEndereco() const;
    void mudarSenha(string new_password);
    void mudarEndereco(string new_address);
    void mudarTelefone(long long int new_phone);
    void adicionarCartao(Cartao new_card);
    string descricao();
};

#endif