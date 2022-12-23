#ifndef PIZZA
#define PIZZA

#include "produtos.hpp"

class Pizza : public Produto
{
    string size, extra;
    bool vegan, stuffed_crust, sweet;

    public:

    Pizza(string nm, float prc, string sz, string ext, bool veg, bool swt);
    void adicionarRecheio();
    string descricao() const override;
};

#endif