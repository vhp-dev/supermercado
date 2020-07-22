#include "cliente.hpp"

#include <iostream>
#include <fstream>

int Cliente::idCliente = 0;

Cliente::Cliente() : sacola(), saldo()
{
    idCliente += 1;
}

Cliente::~Cliente()
{
    registrar();
    sacola.clear();
    saldo = 0;
}

void Cliente::adicionarSaldo()
{
    double valor;

    cout << "Digite valor a ser adicionado ao saldo: ";
    cin >> valor;

    if (valor < 0)
    {
        cout << endl
             << "Não pode adicionar valores negativos. Tente novamente." << endl;
        return;
    }

    this->saldo += valor;
    cout << "Saldo atual do cliente é: " << this->saldo << endl;

    return;
}

void Cliente::comprar_supermercado(Supermercado &supermercado)
{
    int codigoProduto;

    cout << "Digite o codigo: ";
    cin >> codigoProduto; // verificar existencia

    if (supermercado.ha_produto(codigoProduto))
        comprar(supermercado, codigoProduto);
    else
        cout << endl
             << "Esse código não corresponde a um produto" << endl;
}

void Cliente::comprar(Supermercado &supermercado, int codigo)
{
    bool naSacola;
    Produto produtoSacola;

    for (auto &it : supermercado.produtos)
    {
        if (it.codigo == codigo)
        {
            if (it.preco > saldo)
            {
                cout << "Saldo insuficiente." << endl;
                return;
            }
            else if (it.quantidade == 0)
            {
                cout << "Produto fora de estoque." << endl;
                return;
            }
            else
            {
                supermercado.vender(codigo);

                if (sacola.empty())
                {
                    produtoSacola.codigo = it.codigo;
                    produtoSacola.nome = it.nome;
                    produtoSacola.unidadeMedida = it.unidadeMedida;
                    produtoSacola.preco = it.preco;
                    produtoSacola.quantidade = 1;

                    sacola.push_back(produtoSacola);
                    naSacola = true;
                }
                else
                {
                    for (auto &i : sacola)
                    {
                        if (i.codigo == codigo)
                        {
                            i.quantidade += 1;
                            naSacola = true;

                            break;
                        }
                        else
                        {
                            naSacola = false;
                        }
                    }
                    if (naSacola == false)
                    {
                        produtoSacola.codigo = it.codigo;
                        produtoSacola.nome = it.nome;
                        produtoSacola.unidadeMedida = it.unidadeMedida;
                        produtoSacola.preco = it.preco;
                        produtoSacola.quantidade = 1;

                        sacola.push_back(produtoSacola);
                    }
                }

                it.quantidade -= 1;
                saldo -= it.preco;
            }
        }
    }

    return;
}

void Cliente::comprar_restaurante(Restaurante &restaurante)
{
    int quantidadeProduto;
    string nomeProduto;

    cout << "Digite o nome do produto: ";
    cin.ignore();
    getline(cin, nomeProduto);

    if (!restaurante.ha_produto(nomeProduto))
    {
        cout << endl
             << "O restaurante não trabalha com " << nomeProduto << ". Tente novamente." << endl;
        return;
    }

    cout << "Digite a quantidade de " << nomeProduto << " que deseja comprar: ";
    cin >> quantidadeProduto; //Se entrar com uma letra quebra o programa
    if (cin.fail())
    {
        cout << "A quantidade deve ser um numero." << endl;
        cin.clear();
        cin.ignore(100, '\n');
        return;
    }

    if (quantidadeProduto < 1)
    {
        cout << endl
             << "Quantidade tem que ser maior do que 0. Tente novamente." << endl;
        return;
    }

    comprar(restaurante, nomeProduto, quantidadeProduto);
}

void Cliente::comprar(Restaurante &restaurante, string nome, int quantidade)
{
    bool naSacola;
    Produto produtoSacola;

    for (auto &it : restaurante.produtos)
    {
        if (it.nome == nome)
        {
            if (it.preco * quantidade > saldo) //VERIFICAR
            {
                cout << "Saldo insuficiente." << endl;
                return;
            }
            else
            {
                restaurante.vender(nome, quantidade);

                if (sacola.empty())
                {
                    produtoSacola.nome = it.nome;
                    produtoSacola.preco = it.preco;
                    produtoSacola.quantidade = quantidade; //VERIFICAR

                    sacola.push_back(produtoSacola);
                    naSacola = true;
                }
                else
                {
                    for (auto &i : sacola)
                    {
                        if (i.nome == nome)
                        {
                            i.quantidade += quantidade; //VERIFICAR
                            naSacola = true;

                            break;
                        }
                        else
                        {
                            naSacola = false;
                        }
                    }
                    if (naSacola == false)
                    {
                        produtoSacola.nome = it.nome;
                        produtoSacola.preco = it.preco;
                        produtoSacola.quantidade = quantidade; //VERIFICAR

                        sacola.push_back(produtoSacola);
                    }
                }

                // it.quantidade -= quantidade; //VERIFICAR
                saldo -= quantidade * it.preco; //VERIFICAR
            }
        }
    }
    return;
}

void Cliente::verSacola()
{
    cout << "==============================  SACOLA  ==============================" << endl;
    cout << endl;

    if (sacola.empty())
    {
        cout << "Sacola está vazia" << endl;
    }
    else
    {
        for (auto &i : sacola)
        {
            cout << "Nome do produto: " << i.nome << " - Quantidade: " << i.quantidade << endl;
        }
    }

    cout << "======================================================================" << endl;
    cout << endl;
}

void Cliente::registrar()
{
    ofstream file_stream_in("cliente_" + to_string(idCliente) + ".txt"); //ofstream: Stream class to write into files

    for (auto &i : sacola)
    {
        file_stream_in << i.nome << " - Quantidade: " << i.quantidade << endl;
    }

    file_stream_in.close();
}
