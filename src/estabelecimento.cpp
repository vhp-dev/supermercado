#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "estabelecimento.hpp"

Estabelecimento::Estabelecimento() : produtos(), vendas()
{
}

Estabelecimento::~Estabelecimento()
{
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




