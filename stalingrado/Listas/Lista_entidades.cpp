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
    Lista<Entidades::Entidade>::Elemento* pAux = LEs.getPrimeiro();

    // 2. Loop para navegar nó por nó até o fim da lista
    while(pAux != NULL){
        // 3. Pega a entidade que está guardada dentro do nó
        Entidades::Entidade* pEntidade = pAux->getInfo();

        // 4. Se o ponteiro for válido, executa
        if(pEntidade != NULL){
            pEntidade->executar();
        }

        // 5. Passa para o próximo nó
        pAux = pAux->getProx();
    }   
}

void ListaEntidades::desenhar(){
    Lista<Entidades::Entidade>::Elemento* pAux = LEs.getPrimeiro();

    // 2. Loop para navegar nó por nó até o fim da lista
    while(pAux != NULL){
        // 3. Pega a entidade que está guardada dentro do nó
        Entidades::Entidade* pEntidade = pAux->getInfo();

        // 4. Se o ponteiro for válido, executa
        if(pEntidade != NULL){
            pEntidade->desenhar();
        }

        // 5. Passa para o próximo nó
        pAux = pAux->getProx();
    }   
}

void ListaEntidades::remover(Entidades::Entidade *pE){
    LEs.remover(pE);
}

void ListaEntidades::limpar(){
    LEs.limpar();
}

}

} // Fim do namespace Stalingrado
