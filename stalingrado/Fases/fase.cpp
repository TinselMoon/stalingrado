#include "fase.hpp"

namespace Stalingrado {

namespace Fases{

//INICIO CLASSE ABSTRATA FASE
Fase::Fase(Entidades::Personagens::Jogador *pJogador1, Entidades::Personagens::Jogador *pJogador2) : Ente(), GC(pJogador1, pJogador2), lista_ents(), chao(), maxInimMedios(5){

}

Fase::~Fase(){

}

void Fase::criarInimMedios(){

}
void Fase::criarPlataformas(){

}

}

} // Fim do namespace Stalingrado
