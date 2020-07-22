#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "produto.hpp"
#include "supermercado.hpp"
#include "restaurante.hpp"

#include <string>

using namespace std;

class Cliente
{
public:
    Cliente();
    ~Cliente();

    double saldo;                        //Quanto o cliente tem de dinheiro e pode gastar nas compras
    vector_supermercado<Produto> sacola; //Todas as compras do cliente
    static int idCliente;

    void adicionarSaldo();                                //Adiciona valor ao saldo do cliente
    void comprar_supermercado(Supermercado &supermercado);
    void comprar(Supermercado &supermercado, int codigo); //Recece produto e preco, cliente tem saldo ? compra (add na sacola) e diminui saldo : emite aviso
    void comprar_restaurante(Restaurante &restaurante);
    void comprar(Restaurante &restaurante, string nome, int quantidade);
    void verSacola(); //Mostra o que tem na sacola
    void registrar(); //Escreve o conteudo da sacola no arqv. cliente_x.txt (x é o numero do cliente)
};

#endif // !CLIENTE_HPP