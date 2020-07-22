#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

using namespace std;

class Produto
{

public:
    Produto();
    // ~Produto();
    int codigo;
    string nome;
    string unidadeMedida;
    double preco;
    int quantidade;
};

#endif // !PRODUTO_HPP
