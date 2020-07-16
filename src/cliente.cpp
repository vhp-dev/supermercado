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
    this->saldo += valor;
    cout << "Saldo atual do cliente é: " << this->saldo << endl;
}

void Cliente::comprar(Estabelecimento &supermercado)
{
    int codigoProduto;
    cout << "Digite o codigo do produto: ";
    cin >> codigoProduto;
    comprar(supermercado, codigoProduto);
}

void Cliente::comprar(Estabelecimento &supermercado, int codigo)
{
    bool naSacola;
    Produto produtoSacola;

    for (std::list<Produto>::iterator it = supermercado.produtos.begin(); it != supermercado.produtos.end(); it++)
    {
        if (it->codigo == codigo)
        {
            if (it->preco > saldo)
            {
                cout << "Saldo insuficiente." << endl;
                return;
            }
            else if (it->quantidade == 0)
            {
                cout << "Produto fora de estoque." << endl;
                return;
            }
            else
            {
                supermercado.vender(codigo);

                if (sacola.empty())
                {
                    produtoSacola.codigo = it->codigo;
                    produtoSacola.nome = it->nome;
                    produtoSacola.unidadeMedida = it->unidadeMedida;
                    produtoSacola.preco = it->preco;
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
                        produtoSacola.codigo = it->codigo;
                        produtoSacola.nome = it->nome;
                        produtoSacola.unidadeMedida = it->unidadeMedida;
                        produtoSacola.preco = it->preco;
                        produtoSacola.quantidade = 1;

                        sacola.push_back(produtoSacola);
                    }
                }

                it->quantidade -= 1;
                saldo -= it->preco;
            }
        }
    }
    return;
}

void Cliente::verSacola()
{
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