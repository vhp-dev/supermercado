#ifndef MENUSUPERMERCADO_HPP
#define MENUSUPERMERCADO_HPP

#include <iostream>

#include "cliente.hpp"

#include "restaurante.hpp"
#include "supermercado.hpp"

#include "fornecedor.hpp"

class MenuSupermercado
{
public:
    Supermercado &supermercado;
    Cliente &cliente;
    Fornecedor &fornecedor;

    MenuSupermercado(Supermercado &supermercado, Cliente &cliente, Fornecedor &fornecedor);
    void show_options();
    void actions();
};

#endif // !MENUSUPERMERCADO_HPP