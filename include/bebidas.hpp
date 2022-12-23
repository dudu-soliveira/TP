#ifndef BEBIDA
#define BEBIDA

#include "produtos.hpp"

class Bebida: public Produto
{
    int volume;
    bool sugar, alcohol;
    int alcohol_percentage;

    public:

    Bebida(string nm, float prc, int vol, bool alc, int percent);
    void semAcucar();
    void semAlcool();
    string descricao() const override;
};

#endif