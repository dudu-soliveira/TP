#include "cardapio.hpp"

Cardapio::Cardapio()
{}

void Cardapio::adicionarProduto(Produto* prod)
{
    if(prod->getTipo() == "Hamburguer")
    {
        Hamburguer* ham = dynamic_cast<Hamburguer*>(prod);
        hamburguers.insert(pair<string,Hamburguer*>(ham->getNome(),ham));
        return;
    }
    if(prod->getTipo() == "Pizza")
    {
        Pizza* piz = dynamic_cast<Pizza*>(prod);
        pizzas.insert(pair<string,Pizza*>(piz->getNome(),piz));
        return;
    }
    if(prod->getTipo() == "Carne")
    {
        Carne* crn = dynamic_cast<Carne*>(prod);
        carnes.insert(pair<string,Carne*>(crn->getNome(),crn));
        return;
    }
    if(prod->getTipo() == "Bebida")
    {
        Bebida* beb = dynamic_cast<Bebida*>(prod);
        bebidas.insert(pair<string,Bebida*>(beb->getNome(),beb));
        return;
    }
}

void Cardapio::removerProduto(string prod)
{
    if(hamburguers.find(prod) != hamburguers.end())
    {
        hamburguers.erase(prod);
        return;
    }
    if(pizzas.find(prod) != pizzas.end())
    {
        pizzas.erase(prod);
        return;
    }
    if(carnes.find(prod) != carnes.end())
    {
        carnes.erase(prod);
        return;
    }
    if(bebidas.find(prod) != bebidas.end())
    {
        bebidas.erase(prod);
        return;
    }
}

void Cardapio::adicionarPromocao(string prod, float desconto)
{
    if(hamburguers.find(prod) != hamburguers.end())
    {
        hamburguers.find(prod)->second->adicionarPromocao(desconto);
        return;
    }
    if(pizzas.find(prod) != pizzas.end())
    {
        pizzas.find(prod)->second->adicionarPromocao(desconto);
        return;
    }
    if(carnes.find(prod) != carnes.end())
    {
        carnes.find(prod)->second->adicionarPromocao(desconto);
        return;
    }
    if(bebidas.find(prod) != bebidas.end())
    {
        bebidas.find(prod)->second->adicionarPromocao(desconto);
        return;
    }
}

void Cardapio::mudarPreco(string prod, float novo_preco)
{
    if(hamburguers.find(prod) != hamburguers.end())
    {
        hamburguers.find(prod)->second->setPreco(novo_preco);
        return;
    }
    if(pizzas.find(prod) != pizzas.end())
    {
        pizzas.find(prod)->second->setPreco(novo_preco);
        return;
    }
    if(carnes.find(prod) != carnes.end())
    {
        carnes.find(prod)->second->setPreco(novo_preco);
        return;
    }
    if(bebidas.find(prod) != bebidas.end())
    {
        bebidas.find(prod)->second->setPreco(novo_preco);
        return;
    }
}

string Cardapio::getDescricao(string prod)
{
    if(hamburguers.find(prod) != hamburguers.end())
    {
        return hamburguers.find(prod)->second->descricao();
    }
    if(pizzas.find(prod) != pizzas.end())
    {
        return pizzas.find(prod)->second->descricao();
    }
    if(carnes.find(prod) != carnes.end())
    {
        return carnes.find(prod)->second->descricao();
    }
    if(bebidas.find(prod) != bebidas.end())
    {
        return bebidas.find(prod)->second->descricao();
    }
}

string Cardapio::getCardapio() const
{
    string menu = "============================== HAMBURGUERS ==============================\n\n";
    for(auto ptr: hamburguers)
    {
        menu += ptr.second->descricao();
    }
    menu += "\n============================== PIZZAS ==============================\n\n";
    for(auto ptr: pizzas)
    {
        menu += ptr.second->descricao();
    }
    menu += "\n============================== CARNES ==============================\n\n";
    for(auto ptr: carnes)
    {
        menu += ptr.second->descricao();
    }
    menu += "\n============================== BEBIDAS ==============================\n\n";
    for(auto ptr: bebidas)
    {
        menu += ptr.second->descricao();
    }
    return menu;
}

bool Cardapio::produtoExiste(string prod)
{
    if(hamburguers.find(prod) != hamburguers.end())
    {
        return true;
    }
    if(pizzas.find(prod) != pizzas.end())
    {
        return true;
    }
    if(carnes.find(prod) != carnes.end())
    {
        return true;
    }
    if(bebidas.find(prod) != bebidas.end())
    {
        return true;
    }
    return false;
}

Cardapio::~Cardapio()
{
    if(hamburguers.empty() == false)
    {
        hamburguers.~map();
    }
    if(pizzas.empty() == false)
    {
        pizzas.~map();
    }
    if(carnes.empty() == false)
    {
        carnes.~map();
    }
    if(bebidas.empty() == false)
    {
        bebidas.~map();
    }
}