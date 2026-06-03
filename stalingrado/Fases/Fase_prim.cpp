#include "Fase_prim.hpp"
#include "../Entidades/Entidade.hpp"
#include "../Entidades/Personagens/Inim_facil.hpp"
#include "../Entidades/Personagens/Jogador.hpp"

namespace Stalingrado{

namespace Fases{

Fase_prim::Fase_prim(Entidades::Personagens::Jogador *pJogador1, Entidades::Personagens::Jogador *pJogador2) : Fase(pJogador1, pJogador2), maxInimFaceis(3){
    //Aqui eu devo criar a fase, configurar a posição de cada inimigo, jogador e obstáculo
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
    lista_ents.limpar();
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
    chao.setPosition(0, 200);
    chao.setSize(sf::Vector2f(1000.f, 600.f));
    chao.setFillColor(sf::Color::White);

    //criarInimigos();
}

void Fase_prim::executar(){
    lista_ents.percorrer();
    GC.executar();
    lista_ents.desenhar();
}

}

}
