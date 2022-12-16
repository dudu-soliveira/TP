#ifndef PRODUTO
#define PRODUTO

#include <string>

using namespace std;

class Produto
{
    protected:

    string name, type;
    float price;

    public:

    Produto(string& nm, string tp, float prc);
    virtual ~Produto() = default;
    virtual string descricao() const = 0;
    void adicionarPromocao(float percent);
    string getNome();
    string getTipo();
    float getPreco();
};

#endif