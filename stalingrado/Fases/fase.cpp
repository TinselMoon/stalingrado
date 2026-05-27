#include "fase.hpp"

namespace Stalingrado {

namespace Fases{

//INICIO CLASSE ABSTRATA FASE
Fase::Fase() : Ente(), GC(), lista_ents(), chao(), maxInimMedios(5){

}

Fase::~Fase(){

}

void Fase::criarInimMedios(){

}
void Fase::criarPlataformas(){

}

}

} // Fim do namespace Stalingrado
