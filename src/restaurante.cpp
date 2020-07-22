#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

#include "restaurante.hpp"

using namespace std;

Restaurante::Restaurante()
{
    carregar();
}

Restaurante::~Restaurante()
{
    Estabelecimento::caixa();
    gerarCaixa();
}

void Restaurante::listar()
{
    cout << endl;
    cout << "==============================  PRODUTOS  ==============================" << endl;
    cout << "NOME DO PRODUTO | PREÇO" << endl;

    for (auto &it : produtos)
    {
        cout << it.nome << " | "
             << "R$ " << fixed << setprecision(2) << it.preco << endl;
    }
    cout << "========================================================================" << endl;
    cout << endl;
}

void Restaurante::gerarCaixa()
{
    double total;
    ofstream file_stream_in("caixa_restaurante.csv"); //ofstream: Stream class to write into files

    for (auto i : vendas)
    {
        file_stream_in << i.nome;
        file_stream_in << ',';

        file_stream_in << i.quantidade;

        total += (i.preco * i.quantidade);

        file_stream_in << endl;
    }

    file_stream_in << "Total vendido: ";

    file_stream_in << total << endl;

    file_stream_in.close();
}

void Restaurante::carregar()
{
    ifstream file_stream_out("menu.csv"); //ifstream: Stream class to read from files

    Produto produto;
    string row;

    std::getline(file_stream_out, row); //Descarta primeira linha com o cabeçalho

    while (std::getline(file_stream_out, row))
    {

        stringstream line_stream(row);
        string word;

        std::getline(line_stream, word, ',');
        produto.nome = word;

        std::getline(line_stream, word, ',');
        produto.preco = stod(word.substr(3, word.length() - 1));

        produtos.push_back(produto);
    }

    file_stream_out.close();

    return;
}

void Restaurante::vender(string nome, int quantidade)
{
    bool emVendas;
    Produto produtoVenda;

    for (auto &it : produtos)
    {
        if (it.nome == nome)
        {
            if (vendas.empty())
            {
                produtoVenda.nome = it.nome;
                produtoVenda.preco = it.preco;
                produtoVenda.quantidade = quantidade; //VERIFICAR

                vendas.push_back(produtoVenda);
                emVendas = true;
            }
            else
            {
                for (auto &i : vendas)
                {
                    if (i.nome == nome)
                    {
                        i.quantidade += quantidade; //VERIFICAR
                        emVendas = true;

                        break;
                    }
                    else
                    {
                        emVendas = false;
                    }
                }
                if (emVendas == false)
                {
                    produtoVenda.nome = it.nome;
                    produtoVenda.preco = it.preco;
                    produtoVenda.quantidade = quantidade; //VERIFICAR

                    vendas.push_back(produtoVenda);
                }
            }
        }
    }
}

bool Restaurante::ha_produto(string nome)
{
    for (auto &i : produtos)
    {
        if (i.nome == nome)
            return true;
    }
    return false;        
}