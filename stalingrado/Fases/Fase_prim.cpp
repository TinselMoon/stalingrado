#include "Fase_prim.hpp"

namespace Stalingrado{

namespace Fases{

Fase_prim::Fase_prim() : Fase(), maxInimMedios(MAXINIMMED){

}

Fase_prim::~Fase_prim(){

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
    chao.setSize(sf::Vector2f(1000.f, 200.f));
    chao.setFillColor(sf::Color::White);

    //criarInimigos();
}

void Fase_prim::executar(){
    pGG->
}

}

}
