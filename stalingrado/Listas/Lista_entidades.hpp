#pragma once
#include "listas.hpp"
#include "../Entidades/Entidade.hpp"

namespace Stalingrado {


namespace Listas {
class ListaEntidades{
private:
    Lista<Entidades::Entidade>LEs;
public:
    ListaEntidades();
    ~ListaEntidades();
    void incluir(Entidades::Entidade* pE);
    void percorrer();
    void desenhar();
    void remover(Entidades::Entidade *pE);
    void destruirEntidades();
    void limpar();
    //Adicionar mais funções conforme necessário
};

}



} // Fim do namespace Stalingrado
