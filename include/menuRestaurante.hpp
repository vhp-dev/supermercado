#ifndef MENURESTAURANTE_HPP
#define MENURESTAURANTE_HPP

#include <iostream>

#include "cliente.hpp"

#include "restaurante.hpp"
#include "supermercado.hpp"

#include "fornecedor.hpp"

class MenuRestaurante
{
public:
    Restaurante &restaurante;
    Cliente &cliente;

    MenuRestaurante(Restaurante &restaurante, Cliente &cliente);
    void show_options_Restaurante();
    void actions_Restaurante();
};

#endif // !MENURESTAURANTE_HPP