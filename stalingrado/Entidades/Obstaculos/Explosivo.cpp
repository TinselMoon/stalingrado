#include "Explosivo.hpp"

#include <iostream>

#include "../Personagens/Jogador.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Obstaculos {

Explosivo::Explosivo() : Obstaculo(true, false, "Explosivo"), danosidade(0){

}

Explosivo::~Explosivo(){
}

void Explosivo::executar(){

}

void Explosivo::salvar(){
}

void Explosivo::obstaculizar(Personagens::Jogador* pJ){

    if (pJ == NULL) {
        std::cerr << "Ponteiro do jogador nulo" << std::endl;
        exit(1);
    }
    pJ->operator-=(danosidade ? danosidade : pJ->getVida());
    pJ->eliminar();
    ativo = false;
    personagem.setPosition(-100.f, -100.f);
}

}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
