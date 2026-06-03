#include "fase.hpp"

namespace Stalingrado {

namespace Fases{

//INICIO CLASSE ABSTRATA FASE
Fase::Fase(Entidades::Personagens::Jogador *pJogador1, Entidades::Personagens::Jogador *pJogador2) : Ente(), GC(pJogador1, pJogador2), lista_ents(), maxInimMedios(5){
    pJog1 = pJogador1;
    pJog2 = pJogador2;
}

Fase::~Fase(){

}

void Fase::criarInimMedios(){

}
void Fase::criarPlataformas(){

}

}

} // Fim do namespace Stalingrado
