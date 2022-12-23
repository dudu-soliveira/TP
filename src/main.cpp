#include <iostream>
#include <iomanip>
#include "cardapio.hpp"
#include "sistema_contas.hpp"

int main()
{
    Cardapio menu;
    Hamburguer* cheeseburguer =  new Hamburguer("Cheeseburguer_boi", 24.90, "boi", "maionese_artesanal", "cheddar", false, 1);
    Hamburguer* cheeseburguer_super =  new Hamburguer("Cheeseburguer_boi_super", 39.90, "boi", "barbecue, maionese_artesanal", "cheddar", true, 2);
    Hamburguer* cheeseburguer_cordeiro =  new Hamburguer("Cheeseburguer_cordeiro", 44.90, "cordeiro", "de_hortela, maionese_artesanal", "cheddar", false, 1);
    Hamburguer* cheeseburguer_cordeiro_super =  new Hamburguer("Cheeseburguer_super", 54.90, "cordeiro", "de_hortela, maionese_artesanal", "cheddar", true, 2);
    Hamburguer* cheese_mignon =  new Hamburguer("Cheese_Mignon", 34.90, "tiras_de mignon", "maionese_artesanal", "cheddar", true, 1);
    Hamburguer* choripan =  new Hamburguer("Choripan", 39.90, "linguica_defumada", "maionese_artesanal, vinagrete", "prato", true, 1);
    Hamburguer* cheese_chicken =  new Hamburguer("Cheese_chicken crispy", 39.90, "frango_empanado", "maionese_artesanal, vinagrete", "prato", true, 2);
    Hamburguer* vegetariano =  new Hamburguer("Vegetariano", 29.90, "vegano", "de_pimentas-verdes, creme_de_palmito", "prato", true, 0);
    Hamburguer* vegetariano_falafel =  new Hamburguer("Falafel_vegetariano", 34.90, "de_falafel", "maionese_artesanal", "cheddar", true, 0);
    
    Bebida* teste = new Bebida("a", 12.21, 12, true, 12.3);
    Bebida* caipirinha = new Bebida("Caipirinha", 24.90, 300, true, 20);

    Pizza* calabresa = new Pizza("Calabresa", 40.00, "media", "com_queijo_cheddar", false, false);
    
    Carne* cordeiro = new Carne("Cordeiro", 50.00, "bem_passado", "com_molho_barbecue");
    
    menu.adicionarProduto(cheeseburguer);
    menu.adicionarProduto(cheeseburguer_super);
    menu.adicionarProduto(cheeseburguer_cordeiro);
    menu.adicionarProduto(cheeseburguer_cordeiro_super);
    menu.adicionarProduto(cheese_mignon);
    menu.adicionarProduto(choripan);
    menu.adicionarProduto(cheese_chicken);
    menu.adicionarProduto(vegetariano);
    menu.adicionarProduto(vegetariano_falafel);
    menu.adicionarProduto(teste);
    menu.adicionarProduto(caipirinha);
    menu.adicionarProduto(calabresa);
    menu.adicionarProduto(cordeiro);
    menu.removerProduto("a");

    Sistema contas;
    Pessoal* dudu = new Pessoal("Dudu3000", "senha123", "Eduardo", "Rua_Minas_123", "dudu@gmail.com", 19, 12345678910, 912345678);
    Pessoal* artur = new Pessoal("Tuzao1234", "123senha", "Artur", "Rua_Pernambuco_321", "artur@gmail.com", 20, 19876543211, 987654321);
    Pessoal* gui = new Pessoal("Gui2003", "123senha123", "Guilherme", "Rua_Ceara_123", "gui@gmail.com", 19, 12345678910, 947294753);
    Adm* flavio = new Adm("Flavioadm", "Senha_administracao123", "Flavio", "flavio@gmail.com", "dono", "9678");
    Cartao visa1("Credito", "1234567891011123", "11/24", "Artur_de_Albuquerque", "Visa", 123);
    Cartao visa2("Debito", "1987651243014321", "01/23", "Artur_de_Albuquerque", "Mastercard", 321);
    
    artur->adicionarCartao(visa1);
    artur->adicionarCartao(visa2);
    contas.adicionarCliente(dudu);
    contas.adicionarCliente(artur);
    contas.adicionarCliente(gui);
    contas.adicionarFuncionario(flavio);
    
    string comando;
    while(1)
    {
        cout << "============== Seja bem-vindo ao restaurante! ==============\n\n";
        string entrada;
        do
        {
            cout << "Voce ja tem uma conta?(sim/nao)\n";
            cin >> entrada;
        } while(entrada != "sim" && entrada != "nao");
        string conta, senha;
        if(entrada == "sim")
        {
            do
            {
                cout << "Digite seu username: ";
                cin >> conta;
                cout << "Digite sua senha: ";
                cin >> senha;
                cout << contas.acessarConta(conta, senha);
            } while(contas.acessarConta(conta, senha) != "");
        }
        if(entrada == "nao")
        {
            do
            {
                cout << "Digite um username: ";
                cin >> conta;
                if(contas.contaNova(conta) == false)
                {
                    cout << "Username nao disponivel\n";
                }
            } while (contas.contaNova(conta) == false);
            
            do
            {
                cout << "Digite uma senha: ";
                cin >> senha;
                if(senha.length() < 6 || senha.length() > 30)
                {
                    cout << "Senha deve ter entre 6 e 30 caracteres\n";
                }
            } while (senha.length() < 6 || senha.length() > 30);
            if(conta.substr(conta.length() - 4) == "adm" && senha == "Senha_administracao123")
            {
                string nome, email, trabalho, telefone;
                cout << "Digite seu primeiro nome: ";
                cin >> nome;
                cout << "Digite seu e-mail: ";
                cin >> email;
                cout << "Digite sua ocupacao: ";
                cin >> trabalho;
                cout << "Digite seu telefone: ";
                cin >> telefone;
                Adm* conta_nova = new Adm(conta, senha, nome, email, trabalho, telefone);
                contas.adicionarFuncionario(conta_nova);
            }
            else
            {
                string nome, endereco, email;
                int idade;
                long long int id, telefone;
                cout << "Digite seu primeiro nome: ";
                cin >> nome;
                cout << "Digite seu endereco(use _ no lugar de espaco): ";
                cin >> endereco;
                cout << "Digite seu e-mail: ";
                cin >> email;
                cout << "Digite sua idade: ";
                cin >> idade;
                cout << "Digite seu cpf: ";
                cin >> id;
                cout << "Digite seu telefone: ";
                cin >> telefone;
                Pessoal* conta_nova = new Pessoal(conta, senha, nome, endereco, email, idade, id, telefone);
                contas.adicionarCliente(conta_nova);
            }
        }
        if(contas.getPrioridade(conta) == 1)
        {
            cout << "\nSeja bem-vindo " + contas.getNome(conta) + "!";
            cout << "\nDigite o comando que voce deseja realizar\n\nAdicionar_produto\nRemover_produto\nAdicionar_promocao\nMudar_preco\nVer_perfil\nVer_cardapio\nRemover_conta\nVer_contas\nSair\nHelp\n";
            while(comando != "Sair")
            {  
                do
                {
                    cin >> comando;
                    if(comando != "Ver_perfil" && comando != "Adicionar_produto" && comando != "Remover_produto" && comando != "Adicionar_promocao" && comando != "Mudar_preco" && comando != "Ver_cardapio" && comando != "Remover_conta" && comando != "Ver_contas" && comando != "Sair" && comando != "Help")
                    {
                        cout << "Comando invalido\n";
                    }
                } while (comando != "Ver_perfil" && comando != "Adicionar_produto" && comando != "Remover_produto" && comando != "Adicionar_promocao" && comando != "Mudar_preco" && comando != "Ver_cardapio" && comando != "Remover_conta" && comando != "Ver_contas" && comando != "Sair" && comando != "Help");
                if(comando == "Help")
                {
                    cout << "\nDigite o comando que voce deseja realizar\n\nAdicionar_produto\nRemover_produto\nAdicionar_promocao\nMudar_preco\nVer_perfil\nVer_cardapio\nRemover_conta\nVer_contas\nSair\nHelp\n";
                    continue;
                }
                if(comando == "Ver_perfil")
                {
                    cout << "\n" << contas.getDescricao(conta);
                }
                if(comando == "Ver_contas")
                {
                    cout << endl << contas.descricaoGeral();
                }
                if(comando == "Adicionar_produto")
                {
                    string categoria;
                    do
                    {
                        cout << "Qual a categoria do produto que sera adicionado?(Hamburguer/Pizza/Carne/Bebida)\n";
                        cin >> categoria;
                        if(categoria != "Hamburguer" && categoria != "Pizza" && categoria != "Carne" && categoria != "Bebida")
                        {
                            cout << "Categoria nao valida\n";
                        }
                    } while (categoria != "Hamburguer" && categoria != "Pizza" && categoria != "Carne" && categoria != "Bebida");
                    if(categoria == "Hamburguer")
                    {
                        string nome_ham, carne, molho, queijo, salada;
                        float preco;
                        int numero_carnes;
                        cout << "Qual o nome do hamburguer?\n";
                        cin >> nome_ham;
                        cout << "Qual a carne do hamburguer?\n";
                        cin >> carne;
                        cout << "Qual o molho do hamburguer?\n";
                        cin >> molho;
                        cout << "Qual o queijo do hamburguer?\n";
                        cin >> queijo;
                        do
                        {
                            cout << "O hamburguer tem salada?(sim/nao)\n";
                            cin >> salada;
                            if(salada != "sim" && salada != "nao")
                            {
                                cout << "Comando invalido\n";
                            }
                        } while (salada != "sim" && salada != "nao");
                        cout << "Qual o preco do hamburguer?\n";
                        cin >> preco;
                        cout << "Quantas carnes tem o hamburguer?\n";
                        cin >> numero_carnes;
                        if(salada == "sim")
                        {
                            Hamburguer* novo_ham =  new Hamburguer(nome_ham, preco, carne, molho, queijo, true, numero_carnes);
                            menu.adicionarProduto(novo_ham);
                        }
                        if(salada == "nao")
                        {
                            Hamburguer* novo_ham =  new Hamburguer(nome_ham, preco, carne, molho, queijo, false, numero_carnes);
                            menu.adicionarProduto(novo_ham);
                        }
                    }
                    if(categoria == "Pizza")
                    {
                        string nome_piz, tamanho, extra, vegetariana, doce;
                        bool veg_aux, doce_aux;
                        float preco;
                        cout << "Qual o nome da pizza?\n";
                        cin >> nome_piz;
                        do
                        {
                            cout << "Qual o tamanho da pizza?(pequena/media/grande/gigante)\n";
                            cin >> tamanho;
                            if(tamanho != "pequena" && tamanho != "media" && tamanho != "grande" && tamanho != "gigante")
                            {
                                cout << "Tamanho invalido\n";
                            }
                        } while (tamanho != "pequena" && tamanho != "media" && tamanho != "grande" && tamanho != "gigante");
                        do
                        {
                            cout << "A pizza e vegetariana?(sim/nao)\n";
                            cin >> vegetariana;
                            if(vegetariana != "sim" && vegetariana != "nao")
                            {
                                cout << "Comando invalido\n";
                            }
                            if(vegetariana == "sim")
                            {
                                veg_aux = true;
                            }
                            else if(vegetariana == "nao")
                            {
                                veg_aux = false;
                            }
                        } while (vegetariana != "sim" && vegetariana != "nao");
                        do
                        {
                            cout << "A pizza e doce?(sim/nao)\n";
                            cin >> doce;
                            if(doce != "sim" && doce != "nao")
                            {
                                cout << "Comando invalido\n";
                            }
                            if(doce == "sim")
                            {
                                doce_aux = true;
                            }
                            else if(doce == "nao")
                            {
                                doce_aux = false;
                            }
                        } while (doce != "sim" && doce != "nao");
                        cout << "Informacao adicional(use _ no lugar de espaco)\n";
                        cin >> extra;
                        cout << "Qual o preco da pizza?\n";
                        cin >> preco;
                        Pizza* nova_piz = new Pizza(nome_piz, preco, tamanho, extra, veg_aux, doce_aux);
                        menu.adicionarProduto(nova_piz);
                    }
                    if(categoria == "Carne")
                    {
                        string nome_car, ponto_car, extra;
                        float preco;
                        cout << "Qual o nome da carne?\n";
                        cin >> nome_car;
                        cout << "Qual o ponto da carne?(use _ no lugar de espaco)\n";
                        cin >> ponto_car;
                        cout << "Informacao adicional(use _ no lugar de espaco)\n";
                        cin >> extra;
                        cout << "Qual o preco da carne?\n";
                        cin >> preco;
                        Carne* nova_car = new Carne(nome_car, preco, ponto_car, extra);
                        menu.adicionarProduto(nova_car);
                    }
                    if(categoria == "Bebida")
                    {
                        string nome_beb, alcool;
                        bool alc_aux;
                        int percentual_alc, volume;
                        float preco;
                        cout << "Qual o nome da bebida?\n";
                        cin >> nome_beb;
                        cout << "Qual o volume do liquido?(ml)\n";
                        cin >> volume;
                        do
                        {
                            cout << "A bebida tem alcool?\n";
                            cin >> alcool;
                            if(alcool != "sim" && alcool != "nao")
                            {
                                cout << "Comando invalido\n";
                            }
                            if(alcool == "sim")
                            {
                                alc_aux = true;
                            }
                            if(alcool == "nao")
                            {
                                alc_aux = false;
                            }
                        } while (alcool != "sim" && alcool != "nao");
                        if(alc_aux == true)
                        {
                            cout << "Qual o percentual de alcool?\n";
                            cin >> percentual_alc;
                        }
                        else
                        {
                            percentual_alc = 0;
                        }
                        cout << "Qual o preco da bebida?\n";
                        cin >> preco;
                        Bebida* nova_beb = new Bebida(nome_beb, preco, volume, alc_aux, percentual_alc);
                        menu.adicionarProduto(nova_beb);
                    }
                }
                if(comando == "Remover_produto")
                {
                    string nome_prod;
                    cout << "Qual o nome do produto que voce quer remover?\n";
                    cin >> nome_prod;
                    menu.removerProduto(nome_prod);
                }
                if(comando == "Adicionar_promocao")
                {
                    string nome_prod;
                    float desconto;
                    cout << "Qual o nome do produto a qual voce quer adicionar a promocao?\n";
                    cin >> nome_prod;
                    cout << "Quanto porcento de desconto voce quer adicionar?\n";
                    cin >> desconto;
                    menu.adicionarPromocao(nome_prod, desconto);
                }
                if(comando == "Mudar_preco")
                {
                    string nome_prod;
                    float preco;
                    cout << "Qual o nome do produto que tera o preco modificado?\n";
                    cin >> nome_prod;
                    cout << "Qual sera o novo preco do produto?\n";
                    cin >> preco;
                    menu.mudarPreco(nome_prod, preco);
                }
                if(comando == "Ver_cardapio")
                {
                    cout << menu.getCardapio();
                }
                if(comando == "Remover_conta")
                {
                    string user;
                    cout << "Qual o username da conta que sera removida?\n";
                    cin >> user;
                    contas.removerConta(user);
                }
            }
        }
        else
        {
            cout << "\nSeja bem-vindo " + contas.getNome(conta) + "!";
            cout << "\nDigite o comando que voce deseja realizar\n\nVer_cardapio\nVer_perfil\nMudar_senha\nMudar_endereco\nMudar_telefone\nAdicionar_cartao\nComprar\nSair\nHelp\n";
            while(comando != "Sair")
            {
                do
                {
                    cin >> comando;
                    if(comando != "Ver_cardapio" && comando != "Ver_perfil" && comando != "Mudar_senha" && comando != "Mudar_endereco" && comando != "Mudar_telefone" && comando != "Adicionar_cartao" && comando != "Comprar" && comando != "Sair" && comando != "Help")
                    {
                        cout << "Comando invalido\n";
                    }
                } while (comando != "Ver_cardapio" && comando != "Ver_perfil" && comando != "Mudar_senha" && comando != "Mudar_endereco" && comando != "Mudar_telefone" && comando != "Adicionar_cartao" && comando != "Comprar" && comando != "Sair" && comando != "Help");
                if(comando == "Help")
                {
                    cout << "\nDigite o comando que voce deseja realizar\n\nVer_cardapio\nVer_perfil\nMudar_senha\nMudar_endereco\nMudar_telefone\nAdicionar_cartao\nComprar\nSair\nHelp\n";
                    continue;
                }
                if(comando == "Ver_cardapio")
                {
                    cout << menu.getCardapio();
                }
                if(comando == "Ver_perfil")
                {
                    cout << "\n" << contas.getDescricao(conta);
                }
                if(comando == "Mudar_senha")
                {
                    string nova_senha, confirma_senha;
                    cout << "Qual a senha antiga?\n";
                    do
                    {
                        cin >> confirma_senha;
                        if(senha != confirma_senha)
                        {
                            cout << "Senha incorreta\n";
                        }
                    } while (senha != confirma_senha);
                    cout << "Qual a nova senha?\n";
                    do
                    {
                        cin >> nova_senha;
                        if(nova_senha.length() < 6 || nova_senha.length() > 30)
                        {
                            cout << "Senha deve ter entre 6 e 30 caracteres\n";
                        }
                    } while (nova_senha.length() < 6 || nova_senha.length() > 30);
                    contas.mudarSenha(conta, nova_senha);
                    senha = nova_senha;
                }
                if(comando == "Mudar_endereco")
                {
                    string novo_end;
                    cout << "Qual e o novo endereco?(use _ no lugar de espaco)\n";
                    cin >> novo_end;
                    contas.mudarEndereco(conta, novo_end);
                }
                if(comando == "Mudar_telefone")
                {
                    long long int novo_tel;
                    cout << "Qual e o novo telefone?\n";
                    cin >> novo_tel;
                    contas.mudarTelefone(conta, novo_tel);
                }
                if(comando == "Adicionar_cartao")
                {
                    string tipo, numero, validade, titular, apelido;
                    int codigo;
                    cout << "Qual o tipo do cartao?(credito/debito/refeicao)\n";
                    do
                    {
                        cin >> tipo;
                        if(tipo != "credito" && tipo != "debito" && tipo != "refeicao")
                        {
                            cout << "Tipo invalido\n";
                        }
                    } while (tipo != "credito" && tipo != "debito" && tipo != "refeicao");
                    cout << "Qual o numero do cartao?\n";
                    cin >> numero;
                    cout << "Qual a validade do cartao?\n";
                    cin >> validade;
                    cout << "Qual o nome do titular do cartao?(use _ no lugar de espaco)\n";
                    cin >> titular;
                    cout << "Qual o codigo do cartao?\n";
                    cin >> codigo;
                    cout << "Qual apelido voce quer dar para o cartao?\n";
                    cin >> apelido;
                    Cartao card(tipo, numero, validade, titular, apelido, codigo);
                    contas.adicionarCartao(conta, card);
                }
                if(comando == "Comprar")
                {
                    string nome_prod, confirmacao;
                    cout << "Qual produto voce deseja comprar?\n";
                    do
                    {
                        cin >> nome_prod;
                        if(menu.produtoExiste(nome_prod) == false)
                        {
                            cout << "Nao vendemos este produto\n";
                        }
                    } while (menu.produtoExiste(nome_prod) == false);
                    cout << "\nVoce tem certeza que quer comprar o seguinte produto?(sim/nao)\n" << menu.getDescricao(nome_prod);
                    do
                    {
                        cin >> confirmacao;
                        if(confirmacao != "sim" && confirmacao != "nao")
                        {
                            cout << "Comando invalido\n";
                        }
                    } while (confirmacao != "sim" && confirmacao != "nao");
                    if(confirmacao == "sim")
                    {
                        cout << "Pedido foi confirmado e sera entregue para " << contas.getEndereco(conta) << endl;
                    }
                    if(confirmacao == "nao")
                    {
                        cout << "Pedido cancelado\n";
                    }
                }
            }
        }
    }
    return 0;
}