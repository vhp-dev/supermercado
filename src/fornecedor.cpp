#include <iostream>
#include <fstream>
#include <sstream>

#include "fornecedor.hpp"

using namespace std;

Fornecedor::Fornecedor() : produtos()
{
    lerArquivo();
}

Fornecedor::~Fornecedor()
{
    atualizarFornecedor();
}

void Fornecedor::listarProdutos()
{
    for (auto &i : produtos)
    {
        cout << i.nome << " " << i.quantidade << endl;
    }

    return;
}

void Fornecedor::repassarProdutos(Estabelecimento &supermercado)
{
    string nomeProduto;
    int quantidade;

    cout << "Digite o nome do produto: ";
    cin >> nomeProduto;
    cout << "Digite a quantidade: ";
    cin >> quantidade;

    for (auto &i : produtos)
    {
        if (i.nome == nomeProduto)
        {
            supermercado.reabastecer(nomeProduto, quantidade);
            i.quantidade -= quantidade;
        }
    }

    return;
}

void Fornecedor::lerArquivo()
{
    ifstream file_stream_out("fornecedor.csv"); //ifstream: Stream class to read from files

    Produto produto;
    string row;

    getline(file_stream_out, row); //Descarta primeira linha com o cabeçalho

    while (getline(file_stream_out, row))
    {
        stringstream line_stream(row);
        string word;

        getline(line_stream, word, ',');
        produto.nome = word;

        getline(line_stream, word);
        produto.quantidade = stoi(word);

        produtos.push_back(produto);
    }

    file_stream_out.close();

    return;
}

void Fornecedor::atualizarFornecedor()
{
    ofstream file_stream_in("fornecedor.csv"); //ofstream: Stream class to write into files

    file_stream_in << "PRODUTO,QUANTIDADE" << endl;

    for (auto i : produtos)
    {
        file_stream_in << i.nome;
        file_stream_in << ',';

        file_stream_in << i.quantidade;

        file_stream_in << endl;
    }

    file_stream_in.close();
}