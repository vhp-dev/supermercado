#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

#include "cliente.hpp"
#include "estabelecimento.hpp"
#include "fornecedor.hpp"

class Menu
{
    public:
        Estabelecimento &supermercado;
        Cliente &cliente;
        Fornecedor &fornecedor;

        Menu(Estabelecimento &supermercado, Cliente &cliente, Fornecedor &fornecedor);
        void show_options();
        void actions();
};


#endif // !MENU_HPP