#include "carnes.hpp"

Carne::Carne(string& nm, float prc, string& rar, string& ext):
       Produto(nm, "Carne", prc), rare(rar), extra(ext), fries(false), salad(false), rice(false)
{}
void Carne::adicionarAcompanhamento(string tp)
{
    if(tp == "fritas")
    {
        fries = true;
        return;
    }
    if(tp == "salada")
    {
        salad = true;
        return;
    }
    if(tp == "arroz")
    {
        rice = true;
        return;
    }
    return;
}
string Carne::descricao() const
{
    string desc = name + " " + to_string(price) + "\n";
    desc = desc + name + " " + rare + " " + extra;
    desc = desc + (fries ? " com acompanhamento de fritas": "");
    desc = desc + (salad ? " com acompanhamento de salada": "");
    desc = desc + (rice ? " com acompanhamento de arroz": "") + ".";
    desc = desc + "\n\n";
    return desc;
}