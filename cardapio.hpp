#ifndef CARDAPIO
#define CARDAPIO

#include <map>

#include "hamburguer.hpp"
#include "pizza.hpp"
#include "carnes.hpp"
#include "bebidas.hpp"

class Cardapio
{
    map<string,Hamburguer*> hamburguers;
    map<string,Pizza*> pizzas;
    map<string,Carne*> carnes;
    map<string,Bebida*> bebidas;

    public:

    void adicionarProduto(Produto* prod);
    void removerProduto(string prod);
    void adicionarPromocao(string prod, float desconto);
    string getCardapio() const;
    ~Cardapio();
};

#endif