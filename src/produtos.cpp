#include "produtos.hpp"

Produto::Produto(string nm, string tp, float prc):
         name(nm), type(tp), price(prc) {}

void Produto::adicionarPromocao(float percent)
{
    price = price * ((100 - percent) / 100);
}
string Produto::getNome()
{
    return name;
}
string Produto::getTipo()
{
    return type;
}
float Produto::getPreco()
{
    return price;
}
void Produto::setPreco(float new_price)
{
    price = new_price;
}