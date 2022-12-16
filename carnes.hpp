#ifndef CARNE
#define CARNE

#include "produtos.hpp"

class Carne : public Produto
{
    string rare, extra;
    bool fries, salad, rice;

    public:

    Carne(string& nm, float prc, string& rar, string& ext);
    void adicionarAcompanhamento(string tp);
    string descricao() const override;
};

#endif