#ifndef ESTABELECIMENTO_HPP
#define ESTABELECIMENTO_HPP

#include "produto.hpp"

#include <list>
#include <vector>

class Estabelecimento
{
    public:
    Estabelecimento();
    ~Estabelecimento();
    list<Produto> produtos;
    vector<Produto> vendas;

    void listar(); //Lista os produtos disponíveis
    void vender(int codigo); //Verifica se há produto no estoque ? sucesso e escreve no arquivo de saida : insucesso
    void caixa(); //Retorna tudo que foi vendido e o total ganho

    void carregarEstoque(); //Consultar os produtos através do arquivo estoque.cvs
    void gerarCaixa(); //Gerar um arquivo caixa.cvs com produtos vendidos e total arrecadado com vendas
    /*O arquivo caixa.csv deve conter o código do produto, nome, preço, a quantidade vendida de cada 
    produto e o total de vendas*/
};

#endif // !ESTABELECIMENTO_HPP
