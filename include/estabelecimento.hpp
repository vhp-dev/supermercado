#ifndef ESTABELECIMENTO_HPP
#define ESTABELECIMENTO_HPP

#include "produto.hpp"
#include "vector_supermercado.hpp"

#include <list>

class Estabelecimento
{
    public:
    Estabelecimento();
    ~Estabelecimento();
    vector_supermercado<Produto> produtos;
    vector_supermercado<Produto> vendas;

    void listar(); //Lista os produtos disponíveis
    void vender(int codigo); //Verifica se há produto no estoque ? sucesso e escreve no arquivo de saida : insucesso
    void caixa(); //Retorna tudo que foi vendido e o total ganho
    void carregarEstoque(); //Consultar os produtos através do arquivo estoque.cvs
    void gerarCaixa(); //Gerar um arquivo caixa.cvs com produtos vendidos e total arrecadado com vendas, o arquivo caixa.csv deve conter o código do produto, nome, preço, a quantidade vendida de cada produto e o total de vendas

    //ATIVIDADE 5
    void reabastecer(string nomeProduto, int quantidade); //esse método é responsável por pegar os produtos na classe Fornecedor e reabastecer o estoque.csv
    void atualizarEstoque(); //Gera o arquivo estoque.csv atualizado
};

#endif // !ESTABELECIMENTO_HPP
