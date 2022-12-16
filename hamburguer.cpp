#include "hamburguer.hpp"

Hamburguer::Hamburguer(string& nm, float prc, string& beef, string& sauc, string& chs, bool sal, bool pic, int meat_amount):
            Produto(nm, "Hamburguer", prc), meat(beef), sauce(sauc), cheese(chs), salad(sal), bacon(false), meat_num(meat_amount) {}

void Hamburguer::adicionarQueijo()
{
    price += 2.50;
}
void Hamburguer::adicionarBacon()
{
    price += 5.0;
    bacon = true;
}
string Hamburguer::descricao() const
{ 
    string desc = name + " " + to_string(price) + "\n";
    desc = desc + "Hamburguer " + (!meat_num ? "": "de ") + meat + (meat_num > 1 ? " com " + to_string(meat_num) + " bifes": "");
    desc = desc + ", com molho " + sauce;
    desc = desc + ", queijo " + cheese;
    desc = desc + (bacon ? ", bacon": "");
    desc = desc + (salad ? " e com salada.": " e sem salada.");
    desc = desc + "\n\n";
    return desc;
}