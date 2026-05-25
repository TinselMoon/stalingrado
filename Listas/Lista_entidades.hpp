#pragma once
#include "listas.hpp"

namespace Entidades{
    class Entidade;
}

namespace Listas {
class ListaEntidades{
private:
    Lista<Entidades::Entidade>LEs;
public:
    ListaEntidades();
    ~ListaEntidades();
    void incluir(Entidades::Entidade* pE);
    void percorrer();
    void remover(Entidades::Entidade *pE);
    //Adicionar mais funções conforme necessário
};

}


