#include "menu.hpp"

int main(int argc, char const *argv[])
{
    Estabelecimento supermercado;
    Cliente cliente;
    Fornecedor fornecedor;
    
    Menu menu(supermercado, cliente, fornecedor);

    menu.actions();
    
    return 0;
}
