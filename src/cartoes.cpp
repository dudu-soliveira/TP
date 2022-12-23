#include "cartoes.hpp"

Cartao::Cartao(string tp, string num, string val, string nome, string nick, int cdg):
        tipo(tp), numero(num), validade(val), titular(nome), apelido(nick), codigo(cdg)
        {}

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
    string dsc = apelido + "  ";
    dsc += tipo + "  ";
    dsc += "..." + numero.substr(12);
    return dsc;
}