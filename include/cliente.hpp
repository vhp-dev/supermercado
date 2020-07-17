#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "produto.hpp"
#include "estabelecimento.hpp"

#include <string>

using namespace std;

class Cliente
{
    public:
    Cliente();
    ~Cliente();

    double saldo; //Quanto o cliente tem de dinheiro e pode gastar nas compras
    vector_supermercado<Produto> sacola; //Todas as compras do cliente
    static int idCliente;

    void adicionarSaldo(); //Adiciona valor ao saldo do cliente
    void comprar(Estabelecimento &supermercado);
    void comprar(Estabelecimento &supermercado, int codigo); //Recece produto e preco, cliente tem saldo ? compra (add na sacola) e diminui saldo : emite aviso
    void verSacola(); //Mostra o que tem na sacola
    void registrar(); //Escreve o conteudo da sacola no arqv. cliente_x.txt (x é o numero do cliente)
};

#endif // !CLIENTE_HPP