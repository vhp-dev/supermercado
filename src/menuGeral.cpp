#include "menuGeral.hpp"

void MenuGeral::show_options()
{

    std::cout << "MENU INICIAL " << endl;
    std::cout << "# Possíveis estabelecimentos: " << endl;
    std::cout << "1 - Supermercado " << endl;
    std::cout << "2 - Restaurante " << endl;
    std::cout << "Digite o código do estabelecimento que deseja utilizar: ";

    actions();
}

void MenuGeral::actions()
{
    Cliente cliente;
    int qualEstabelecimento;

    std::cin >> qualEstabelecimento;

    if (qualEstabelecimento == 1) //SUPERMERCADO
    {
        Fornecedor fornecedor;
        Supermercado supermercado;
        MenuSupermercado menuSupermercado(supermercado, cliente, fornecedor);

        menuSupermercado.actions();
    }
    else if (qualEstabelecimento == 2) //RESTAURANTE
    {
        Restaurante restaurante;
        MenuRestaurante menuRestaurante(restaurante, cliente);

        menuRestaurante.actions_Restaurante();
    }
    else //OPÇÃO INVÁLIDA
    {
        std::cout << "Código de estabelecimento inválido." << std::endl;
    }
}