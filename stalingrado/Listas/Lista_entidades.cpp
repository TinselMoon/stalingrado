#include "Lista_entidades.hpp"

namespace Stalingrado {

namespace Listas{
ListaEntidades::ListaEntidades() : LEs(){

}

ListaEntidades::~ListaEntidades(){
    //IMPLEMENTAR O QUE FOR NECESSÁRIO
    //ao apagar a lista_entidades, automaticamente apaga a Lista e todas as entidades que estiverem nela
}

void ListaEntidades::incluir(Entidades::Entidade *pE){
    LEs.incluir(pE);
}

void ListaEntidades::percorrer(){
    
}

void ListaEntidades::remover(Entidades::Entidade *pE){
    LEs.remover(pE);
}

void ListaEntidades::limpar(){
    LEs.limpar();
}

}

} // Fim do namespace Stalingrado
