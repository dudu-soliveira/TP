#include "sistema_contas.hpp"

Sistema::Sistema()
{}

void Sistema::adicionarFuncionario(Adm* account)
{
    funcionarios.insert(pair<string,Adm*>(account->getUsername(),account));
    return;
}

void Sistema::adicionarCliente(Pessoal* account)
{
    clientes.insert(pair<string,Pessoal*>(account->getUsername(),account));
    return;
}

void Sistema::adicionarCartao(string conta, Cartao card)
{
    if(clientes.find(conta) != clientes.end())
    {
        clientes.find(conta)->second->adicionarCartao(card);
    }
}

void Sistema::removerConta(string conta)
{
    if(funcionarios.find(conta) != funcionarios.end())
    {
        funcionarios.erase(conta);
    }
    if(clientes.find(conta) != clientes.end())
    {
        clientes.erase(conta);
    }
}

string Sistema::acessarConta(string conta, string senha)
{
    if(funcionarios.find(conta) != funcionarios.end())
    {
        if(funcionarios.find(conta)->second->getPassword() == senha)
        {
            return "";
        }
        return "Senha incorreta\n";
    }
    if(clientes.find(conta) != clientes.end())
    {
        if(clientes.find(conta)->second->getPassword() == senha)
        {
            return "";
        }
        return "Senha incorreta\n";
    }
    return "Conta nao existe\n";
}

bool Sistema::contaNova(string conta)
{
    if(funcionarios.find(conta) != funcionarios.end())
    {
        return false;
    }
    if(clientes.find(conta) != clientes.end())
    {
        return false;
    }
    return true;
}

bool Sistema::getPrioridade(string conta)
{
    if(funcionarios.find(conta) != funcionarios.end())
    {
        return 1;
    }
    if(clientes.find(conta) != clientes.end())
    {
        return 0;
    }
}

string Sistema::getNome(string conta)
{
    if(funcionarios.find(conta) != funcionarios.end())
    {
        return funcionarios.find(conta)->second->getName();
    }
    if(clientes.find(conta) != clientes.end())
    {
        return clientes.find(conta)->second->getName();
    }
}

string Sistema::getDescricao(string conta)
{
    if(funcionarios.find(conta) != funcionarios.end())
    {
        return funcionarios.find(conta)->second->descricao();
    }
    if(clientes.find(conta) != clientes.end())
    {
        return clientes.find(conta)->second->descricao();
    }
}


string Sistema::getEndereco(string conta)
{
    if(clientes.find(conta) != clientes.end())
    {
        return clientes.find(conta)->second->getEndereco();
    }
}

void Sistema::mudarSenha(string conta, string new_password)
{
    if(funcionarios.find(conta) != funcionarios.end())
    {
        funcionarios.find(conta)->second->mudarSenha(new_password);
    }
    if(clientes.find(conta) != clientes.end())
    {
        clientes.find(conta)->second->mudarSenha(new_password);
    }
}

void Sistema::mudarEndereco(string conta, string new_address)
{
    if(clientes.find(conta) != clientes.end())
    {
        clientes.find(conta)->second->mudarEndereco(new_address);
    }
}

void Sistema::mudarTelefone(string conta, long long int new_phone)
{
    if(clientes.find(conta) != clientes.end())
    {
        clientes.find(conta)->second->mudarTelefone(new_phone);
    }
}

string Sistema::descricaoGeral()
{
    string desc = "";
    for(auto itr: funcionarios)
    {
        desc += itr.second->descricao() + "\n";
    }
    for(auto itr: clientes)
    {
        desc += itr.second->descricao() + "\n";
    }
    return desc;
}