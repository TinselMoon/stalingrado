#include "fase.hpp"
using namespace Fases;



//INICIO CLASSE ABSTRATA FASE
Fase::Fase() : Ente(), GC(), lista_ents(){

}

Fase::~Fase(){

}

//FIM CLASSE FASE
//
//INICIO FASE PRIM

Fase_prim::Fase_prim() : Fase(), maxInimMedios(MAXINIMMED){

}

Fase_prim::~Fase_prim(){

}
//FIM FASE PRIM
//
//INICIO FASE SEG
Fase_seg::Fase_seg() : Fase(), maxChefoes(MAXCHEFOES){

}

Fase_seg::~Fase_seg(){

}
//FIM FASE SEG
