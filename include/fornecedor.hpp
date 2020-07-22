#ifndef FORNECEDOR_HPP
#define FORNECEDOR_HPP

#include "vector_supermercado.hpp"
#include "produto.hpp"
#include "supermercado.hpp"

using namespace std;

class Fornecedor
{
public:
    vector_supermercado<Produto> produtos;

    Fornecedor();
    ~Fornecedor();
    void listarProdutos();                             //Mostrar todos os produtos disponíveis
    void repassarProdutos(Supermercado &supermercado); //repassa para o estabelecimento os produtos solicitados na quantidade solicitada, diminuindo seus valores em fornecedor.csv

    void lerArquivo();          //Alimenta o vector com os dados do fornecedor.csv
    void atualizarFornecedor(); //Atualiza o arquivo fornecedor.csv
};

#endif // !FORNECEDOR_HPP