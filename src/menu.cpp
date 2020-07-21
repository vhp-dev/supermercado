#include "menu.hpp"

using namespace std;

Menu::Menu(Supermercado &supermercado, Cliente &cliente, Fornecedor &fornecedor) : supermercado(supermercado), cliente(cliente), fornecedor(fornecedor)
{
    
}

//TODO: Ajeitar a entrada para compra

void Menu::show_options()
{
    cout << "++++++++++++++++++++++++++++++  MENU  ++++++++++++++++++++++++++++++" << endl;
    cout << endl;

    cout << "1 - Adicionar saldo para o cliente." << endl;
    cout << endl;

    cout << "2 - Listar os produtos disponiveis na loja." << endl;
    cout << endl;

    cout << "3 - Adicionar produto a sacola (Efetua a compra)." << endl;
    cout << endl;

    cout << "4 - Verificar o conteúdo da sacola." << endl;
    cout << endl;

    cout << "5 - Listar produtos do fornecedor." << endl;
    cout << endl;

    cout << "6 - Solicitar o reabastecimento de um produto." << endl;
    cout << endl;

    cout << "9 - Finalizar compras." << endl;
    cout << endl;

    cout << "Digite a opção desejada: ";

}

void Menu::actions()
{
    char opcao;
    char novoCliente;
    int codigoProduto;

    do
    {
        cout << endl;
        cout << "---------  STATUS CLIENTE  ---------" << endl;
        cout << "-> Cliente atual: " << cliente.idCliente << endl;
        cout << "-> Saldo atual do cliente: R$ " << cliente.saldo << endl;
        cout << "------------------------------------" << endl;
        cout << endl;

        show_options();

        cin >> opcao;

        if (opcao == '1')
        {
            cliente.adicionarSaldo();
        }
        else if (opcao == '2')
        {
            supermercado.listar();
        }
        else if (opcao == '3')
        {
            cout << "Digite o codigo: ";
            cin >> codigoProduto;
            cliente.comprar(supermercado, codigoProduto);
        }
        else if (opcao == '4')
        {
            cliente.verSacola();
        }
        else if (opcao == '5')
        {
            fornecedor.listarProdutos();
        }
        else if (opcao == '6')
        {
            fornecedor.repassarProdutos(supermercado);
        }
        else if (opcao == '9')
        {
            cout << "Inicializar novo cliente? (S/N)" << endl;
            cin >> novoCliente;
            novoCliente = towupper(novoCliente);

            if (novoCliente == 'S')
            {
                cliente.~Cliente();
                Cliente cliente;
            }
            else if (novoCliente == 'N')
            {
                opcao = '0';
                return;
            }
        }
        else
        {
            cout << "Opção inválida!" << endl;
        }
    } while (opcao != 0);
}