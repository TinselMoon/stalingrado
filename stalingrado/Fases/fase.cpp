#include "fase.hpp"

namespace Stalingrado {
using namespace Fases;

namespace Fases{

//INICIO CLASSE ABSTRATA FASE
Fase::Fase() : Ente(), GC(), lista_ents(){

}

Fase::~Fase(){

}

void Fase::criarInimFaceis(){

}
void Fase::criarPlataformas(){

}
void Fase::criarCenario(){

}

void Fase::executar(){

}

//FIM CLASSE FASE
//
//INICIO FASE PRIM

Fase_prim::Fase_prim() : Fase(), maxInimMedios(MAXINIMMED){

}

Fase_prim::~Fase_prim(){

}

void Fase_prim::criarInimMedios(){

}
void Fase_prim::criarArame_farp(){

}

void Fase_prim::criarInimigos(){

}
void Fase_prim::criarObstaculos(){

}


//FIM FASE PRIM
//
//INICIO FASE SEG
Fase_seg::Fase_seg() : Fase(), maxChefoes(MAXCHEFOES){

}

Fase_seg::~Fase_seg(){

}

void Fase_seg::criarChefoes(){

}
void Fase_seg::criarExplosivos(){

}
void Fase_seg::criarProjeteis(){

}

void Fase_seg::criarInimigos(){

}
void Fase_seg::criarObstaculos(){

}


//FIM FASE SEG
}

} // Fim do namespace Stalingrado
