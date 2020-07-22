#include "menuRestaurante.hpp"
#include <exception>

using namespace std;

MenuRestaurante::MenuRestaurante(Restaurante &restaurante, Cliente &cliente) : restaurante(restaurante),
                                                                               cliente(cliente)
{
}

void MenuRestaurante::show_options_Restaurante()
{
    cout << "++++++++++++++++++++++++++++++  MENU RESTAURANTE ++++++++++++++++++++++++++++++" << endl;
    cout << endl;

    cout << "1 - Adicionar saldo para o cliente." << endl;
    cout << endl;

    cout << "2 - Listar os produtos disponíveis no cardápio." << endl;
    cout << endl;

    cout << "3 - Fazer um pedido." << endl;
    cout << endl;

    cout << "4 - Verificar o que tem na conta do cliente (produtos já pedidos)." << endl;
    cout << endl;

    cout << "9 - Finalizar pedidos e sair do restaurante." << endl;
    cout << endl;

    cout << "Digite a opção desejada: ";
}

void MenuRestaurante::actions_Restaurante()
{
    int opcao;
    char novoCliente;
    int codigoProduto;
    cliente.tipoCliente = 2;

    do
    {
        cout << endl;
        cout << "---------  STATUS CLIENTE  ---------" << endl;
        cout << "-> Cliente atual: " << cliente.idCliente << endl;
        cout << "-> Saldo atual do cliente: R$ " << cliente.saldo << endl;
        cout << "------------------------------------" << endl;
        cout << endl;

        show_options_Restaurante();

        cin >> opcao;

        try
        {
            if (cin.fail())
            {
                string temp = "Entrada de dados inválidas: Falhou no tipo ";
                throw(string(temp));
            }
        }
        catch (const string e)
        {
            std::cerr << e << '\n';
        }

        if (opcao == 1)
        {
            cliente.adicionarSaldo();
        }
        else if (opcao == 2)
        {
            restaurante.listar();
        }
        else if (opcao == 3)
        {
            cliente.comprar_restaurante(restaurante);
        }
        else if (opcao == 4)
        {
            cliente.verSacola();
        }
        else if (opcao == 9)
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
            cin.clear();
            cin.ignore(100, '\n');
        }
    } while (opcao != 0);
}
