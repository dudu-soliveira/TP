#ifndef PESSOAL
#define PESSOAL

#include <map>
#include "contas.hpp"
#include "cartoes.hpp"

class Pessoal : public Conta 
{
    string name, address, email;
    int age;
    double cpf, phone_number;
    float saldo;
    map<string,Cartao> cartoes;

    public:

    Pessoal(string user, string psw, string nm, string adr,
            string eml, int ag, double id, double phone);

    void mudarTelefone(double new_phone);
    void mudarSenha(string old_password, string new_password);
    void mudarEndereco(string new_address);
    void adicionarCartao(Cartao new_card);
    void adicionarSaldo(string card, float amount);
};

#endif