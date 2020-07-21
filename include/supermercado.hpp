#ifndef SUPERMERCADO_HPP
#define SUPERMERCADO_HPP

#include "estabelecimento.hpp"

class Supermercado : public Estabelecimento
{
    public:
        Supermercado();
        ~Supermercado();

        void atualizarEstoque(); //Gera o arquivo estoque.csv atualizado
        void carregar();
        void gerarCaixa();
        void listar();
        void reabastecer(string nomeProduto, int quantidade); //esse método é responsável por pegar os produtos na classe Fornecedor e reabastecer o estoque.csv
        void vender(int codigo);
};

#endif // !SUPERMERCADO_HPP