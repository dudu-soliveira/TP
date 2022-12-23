#ifndef HAMBURGUER
#define HAMBURGUER

#include "produtos.hpp"

class Hamburguer: public Produto
{
    string meat, sauce, cheese;
    bool bacon, salad;
    int meat_num;

    public:

    Hamburguer(string nm, float prc, string beef, string sauc, string chs, bool sal, int meat_amount);
    void adicionarQueijo();
    void adicionarBacon();
    string descricao() const override;
};

#endif