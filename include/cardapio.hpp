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

    Cardapio();
    void adicionarProduto(Produto* prod);
    void removerProduto(string prod);
    void adicionarPromocao(string prod, float desconto);
    void mudarPreco(string prod, float novo_preco);
    string getDescricao(string prod);
    string getCardapio() const;
    bool produtoExiste(string prod);
    ~Cardapio();
};

#endif