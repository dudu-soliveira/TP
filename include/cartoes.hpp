#ifndef CARTAO
#define CARTAO

#include <string>

using namespace std;

class Cartao
{
    string tipo, numero, validade, titular, apelido;
    int codigo;

    public:

    Cartao(string tp, string num, string val, string nome, string nick, int cdg);
    ~Cartao() = default;
    void setApelido(string novo_apelido);
    string getApelido();
    string descricao() const;
};

#endif