#include "Fase_prim.hpp"
#include "../Entidades/Entidade.hpp"
#include "../Entidades/Personagens/Inim_facil.hpp"
#include "../Entidades/Personagens/Jogador.hpp"
#include "../Entidades/Chao.hpp"

namespace Stalingrado{

namespace Fases{

Fase_prim::Fase_prim(Entidades::Personagens::Jogador *pJogador1, Entidades::Personagens::Jogador *pJogador2) : Fase(pJogador1, pJogador2), maxInimFaceis(3), chao(NULL){
    //Aqui eu devo criar a fase, configurar a posição de cada inimigo, jogador e obstáculo
    chao = new Entidades::Chao();
    GC.setChao(chao);
    lista_ents.incluir(static_cast<Entidades::Entidade*>(chao));
    for(int i = 0; i < maxInimFaceis; i++){
        Entidades::Personagens::Inim_facil *pEntidade = new Entidades::Personagens::Inim_facil(5, 1);
        GC.incluirInimigo(pEntidade);
        pEntidade->setNewPos(100 + i*350, 600);
        lista_ents.incluir(static_cast<Entidades::Entidade*>(pEntidade));
    }
    lista_ents.incluir(static_cast<Entidades::Entidade*>(pJogador1));
    pJogador1->setNewPos(300.0f, 500.0f);
}

Fase_prim::~Fase_prim(){
    if (pJog1 != NULL) {
        lista_ents.remover(static_cast<Entidades::Entidade*>(pJog1));
    }
    if (pJog2 != NULL) {
        lista_ents.remover(static_cast<Entidades::Entidade*>(pJog2));
    }
}

void Fase_prim::criarInimFaceis(){

}
void Fase_prim::criarArame_farp(){

}

void Fase_prim::criarInimigos(){
    criarInimFaceis();
    criarInimMedios();
}
void Fase_prim::criarObstaculos(){

}

void Fase_prim::criarCenario(){
    //criar o chao aqui e os inimigos e o fundo e os krlh
}

void Fase_prim::executar(){
    lista_ents.percorrer();
    GC.executar();
    lista_ents.desenhar();
}

}

}
