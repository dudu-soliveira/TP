#ifndef SISTEMA_CONTAS
#define SISTEMA_CONTAS

#include "adm.hpp"
#include "pessoal.hpp"

class Sistema
{
    map<string,Adm*> funcionarios;
    map<string,Pessoal*> clientes;

    public:

    Sistema();
    void adicionarFuncionario(Adm* account);
    void adicionarCliente(Pessoal* account);
    void adicionarCartao(string conta, Cartao card);
    void removerConta(string conta);
    string acessarConta(string conta, string senha);
    void mudarSenha(string conta, string new_password);
    void mudarEndereco(string conta, string new_address);
    void mudarTelefone(string conta, long long int new_phone);
    bool contaNova(string conta);
    bool getPrioridade(string conta);
    string getNome(string conta);
    string getDescricao(string conta);
    string getEndereco(string conta);
    string descricaoGeral(); // teste
};

#endif