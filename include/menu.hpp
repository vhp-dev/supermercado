#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

#include "cliente.hpp"

#include "restaurante.hpp"
#include "supermercado.hpp"

#include "fornecedor.hpp"

class Menu
{
    public:
        Supermercado &supermercado;
        Cliente &cliente;
        Fornecedor &fornecedor;

        Menu(Supermercado &supermercado, Cliente &cliente, Fornecedor &fornecedor);
        void show_options();
        void actions();
};


#endif // !MENU_HPP