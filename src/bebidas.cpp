#include "bebidas.hpp"

Bebida::Bebida(string nm, float prc, int vol, bool alc, int percent):
        Produto(nm, "Bebida", prc), volume(vol), sugar(true), alcohol(alc), alcohol_percentage(percent)
{}
void Bebida::semAcucar()
{
    sugar = false;
}
void Bebida::semAlcool()
{
    alcohol = false;
    alcohol_percentage = 0;
}
string Bebida::descricao() const
{
    string desc = name + " " + to_string(price).substr(0, 5) + "\n";
    desc = desc + name + " de " + to_string(volume) + " ml, ";
    desc = desc + (sugar ? "com acucar, ": "sem acucar, ");
    desc = desc + (alcohol ? "com alcool ": "sem alcool ") + (alcohol_percentage ? to_string(alcohol_percentage) + " %.": "."); 
    desc = desc + "\n\n";
    return desc;
}   