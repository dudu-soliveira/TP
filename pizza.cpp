#include "pizza.hpp"

Pizza::Pizza(string& nm, float prc, string& sz, string& ext, bool veg, bool swt):
       Produto(nm, "Pizza", prc), size(sz), extra(ext), vegan(veg), stuffed_crust(false), sweet(swt)
{}
void Pizza::adicionarRecheio()
{
    price += 5.0;
    stuffed_crust = true;
}
string Pizza::descricao() const
{
    string desc = name + " " + to_string(price) + "\n";
    desc = desc + "Pizza " + size + (vegan ? " vegana de ": " de ") + (sweet ? " doce de ": " de ");
    desc = desc + name + " " + extra + (stuffed_crust ? " com borda recheada.": " sem borda recheada.");
    desc = desc + "\n\n";
    return desc;
}