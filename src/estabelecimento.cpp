#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "estabelecimento.hpp"
Estabelecimento::Estabelecimento() : produtos(), vendas()
{
    carregarEstoque();
}

Estabelecimento::~Estabelecimento()
{
    caixa();
    gerarCaixa();
    atualizarEstoque();
}

void Estabelecimento::listar()
{
    cout << "==============================  PRODUTOS  ==============================" << endl;
    cout << endl;

    for (auto &it : produtos)
    {
        if (it.quantidade > 0)
        {
            cout << "Código: " << it.codigo << endl;
            cout << "Nome do produto: " << it.nome << endl;
            cout << "Unidade de medida: " << it.unidadeMedida << endl;
            cout << "Preço: " << "R$ " << fixed << setprecision(2) <<it.preco << endl;
            cout << "Quantidade em estoque: " << it.quantidade << endl;
            cout << endl;
        }
    }

    cout << "========================================================================" << endl;
    cout << endl;
}

void Estabelecimento::vender(int codigo)
{
    bool emVendas;
    Produto produtoVenda;

    for (auto &it : produtos)
    {
        if (it.codigo == codigo)
        {
           if (it.quantidade == 0)
            {
                cout << "Produto fora de estoque." << endl;
            }    
            else
            {
                 if (vendas.empty())
                {
                    produtoVenda.codigo = it.codigo;
                    produtoVenda.nome = it.nome;
                    produtoVenda.unidadeMedida = it.unidadeMedida;
                    produtoVenda.preco = it.preco;
                    produtoVenda.quantidade = 1;

                    vendas.push_back(produtoVenda);
                    emVendas = true;
                }
                else
                {
                    for (auto &i : vendas)
                    {
                        if (i.codigo == codigo)
                        {
                            i.quantidade += 1;
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
                        produtoVenda.codigo = it.codigo;
                        produtoVenda.nome = it.nome;
                        produtoVenda.unidadeMedida = it.unidadeMedida;
                        produtoVenda.preco = it.preco;
                        produtoVenda.quantidade = 1;

                        vendas.push_back(produtoVenda);
                    }
                }
            }
        }
    } 
}

void Estabelecimento::caixa()
{
    double totalItem;
    double total;

    cout << endl;
    cout << "===========================  PRODUTOS VENDIDOS ===========================" << endl;
    cout << endl;

    for (auto &i : vendas)
    {
        cout << "Nome do produto: " << i.nome << " - Quantidade: " << i.quantidade << endl;
        totalItem = i.preco * i.quantidade;
        total += totalItem;
    }

    cout << endl;
    cout << "==========================================================================" << endl;
    cout << endl;

    cout << " ==> Total vendido: " << fixed << setprecision(2) << total << endl;
    return;
}

void Estabelecimento::carregarEstoque()
{
    ifstream file_stream_out("estoque.csv"); //ifstream: Stream class to read from files

    Produto produto;
    string row;

    std::getline(file_stream_out, row); //Descarta primeira linha com o cabeçalho

    while (std::getline(file_stream_out, row))
    {
        stringstream line_stream(row);
        string word;

        std::getline(line_stream, word, ',');
        produto.codigo = stoi(word);

        std::getline(line_stream, word, ',');
        produto.nome = word;

        std::getline(line_stream, word, ',');
        produto.unidadeMedida = word;

        std::getline(line_stream, word, ',');
        produto.preco = stod(word.substr(3, word.length() - 1));

        std::getline(line_stream, word, ',');
        produto.quantidade = stoi(word);

        produtos.push_back(produto);
    }

    file_stream_out.close();

    return;
}

void Estabelecimento::reabastecer(string nomeProduto, int quantidade)
{
    for (auto &i : produtos)
    {
        if (i.nome == nomeProduto)
        {
            i.quantidade += quantidade;
        }
    }

    return;
}

void Estabelecimento::gerarCaixa()
{
    double total;
    ofstream file_stream_in("caixa.csv"); //ofstream: Stream class to write into files

    for (auto i : vendas)
    {
        file_stream_in << i.codigo;
        file_stream_in << ',';

        file_stream_in << i.nome;
        file_stream_in << ',';

        file_stream_in << i.unidadeMedida;
        file_stream_in << ',';

        file_stream_in << i.quantidade;

        total += (i.preco * i.quantidade);

        file_stream_in << endl;
    }

    file_stream_in << "Total vendido: ";

    file_stream_in << total << endl;


    file_stream_in.close();
}

void Estabelecimento::atualizarEstoque()
{
    ofstream file_stream_in("estoque.csv"); //ofstream: Stream class to write into files

    file_stream_in << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO(R$),QUANTIDADE" << endl;

    for (auto i : produtos)
    {
        file_stream_in << i.codigo;
        file_stream_in << ',';

        file_stream_in << i.nome;
        file_stream_in << ',';

        file_stream_in << i.unidadeMedida;
        file_stream_in << ',';

        file_stream_in << "R$ ";
        file_stream_in << i.preco;
        file_stream_in << ',';

        file_stream_in << i.quantidade;

        file_stream_in << endl;
    }

    file_stream_in.close();
}