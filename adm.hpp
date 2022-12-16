#ifndef ADM
#define ADM

#include "contas.hpp"
#include "cardapio.hpp"

class Adm : public Conta
{
    string name, email, job;
    double phone_number;

    public:

    Adm(string user, string psw, string nm,
        string eml, string jb, double phone);
    
    void adicionarProduto(Produto* prod);
    void removerProduto(string prod);
    void removerConta(string user, string psw);
};

#endif