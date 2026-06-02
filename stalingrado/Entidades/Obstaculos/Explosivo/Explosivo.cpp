#include "Explosivo.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Obstaculos {

Explosivo::Explosivo(int dano) : Obstaculo(true, false, "Explosivo"){
    danosidade = dano;
}

Explosivo::~Explosivo(){
}

void Explosivo::executar(){

}

void Explosivo::salvar(){
}

void Explosivo::obstaculizar(Personagens::Jogador* pJ){

}

}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
