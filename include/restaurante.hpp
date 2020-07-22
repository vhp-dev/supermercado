#ifndef RESTAURANTE_HPP
#define RESTAURANTE_HPP

#include "estabelecimento.hpp"

class Restaurante : public Estabelecimento
{
public:
    Restaurante();
    ~Restaurante();

    void listar();                            //Adaptado para o restaurante
    void caixa();                             //Funciona de forma analoga a estabelecimento
    void gerarCaixa();                        //Funciona de forma analoga a estabelecimento
    void carregar();                          //Consultar os produtos através do arquivo estoque.cvs
    void vender(string nome, int quantidade); //TODO implementacao

    bool ha_produto(string nome); //Verifica se trabalha com esse produto ? true : false
};

#endif // !RESTAURANTE