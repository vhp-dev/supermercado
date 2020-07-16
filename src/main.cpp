/*
Conter menu inicializador e os objetos clientes
- adicionar saldo do cliente;
- verificar os produtos da loja;
- ver conteudo da sacola do cliente;
- finalizar as compras => inicializar novo cliente ? prosseguir : encerrar
*/

#include <iostream>
#include "cliente.hpp"
#include "estabelecimento.hpp"

int main(int argc, char const *argv[])
{
    char opcao = 0;
    char novoCliente;
    Estabelecimento supermercado;
    Cliente cliente;

    do
    {
        cout << "1 - Adicionar saldo para o cliente." << endl;

        cout << "2 - Listar os produtos disponiveis na loja." << endl;

        cout << "3 - Adicionar produto a sacola (Efetua a compra)." << endl;

        cout << "4 - Verificar o conteúdo da sacola." << endl;

        cout << "9 - Finalizar compras." << endl;

        cout << "Digite a opção desejada: ";
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
            cliente.comprar(supermercado);
        }
        else if (opcao == '4')
        {
            cliente.verSacola();
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
            }

        }
        else
        {
            cout << "Opção inválida!" << endl;
        }
        

    } while (opcao != '0');
    
    return 0;
}
