#ifndef ESTABELECIMENTO_HPP
#define ESTABELECIMENTO_HPP

#include "produto.hpp"
#include "vector_supermercado.hpp"

class Estabelecimento
{
public:
    vector_supermercado<Produto> produtos;
    vector_supermercado<Produto> vendas;
    Estabelecimento();
    ~Estabelecimento();

    void carregar();   //Consultar os produtos através do arquivo estoque.cvs
    void caixa();      //Retorna tudo que foi vendido e o total ganho
    void gerarCaixa(); //Gerar um arquivo caixa.cvs com produtos vendidos e total arrecadado com vendas, o arquivo caixa.csv deve conter o código do produto, nome, preço, a quantidade vendida de cada produto e o total de vendas
    void listar();     //Lista os produtos disponíveis
    void vender();     //Verifica se há produto no estoque ? sucesso e escreve no arquivo de saida : insucesso
};

#endif // !ESTABELECIMENTO_HPP
