#include "cartoes.hpp"

Cartao::Cartao(string tp, string num, string val, string nome, string nick, int cdg, double id):
        tipo(tp), numero(num), validade(val), titular(nome), apelido(nick), codigo(cdg), cpf(id) {}

void Cartao::setApelido(string novo_apelido)
{
    apelido = novo_apelido;
}
string Cartao::getApelido()
{
    return apelido;
}
string Cartao::descricao() const
{
    string dsc = apelido + "\n";
    dsc = tipo + "\n";
    dsc = "..." + numero.substr(12) + "\n";
    return dsc;
}