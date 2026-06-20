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

void Explosivo::salvar(std::ofstream& arquivo){
    arquivo << id << " EXPLOSIVO " << corpo.getPosition().x
            << " " << corpo.getPosition().y << "\n";
}

void Explosivo::obstaculizar(Personagens::Jogador* pJ){

    if (pJ == nullptr) {
        std::cerr << "Ponteiro do jogador nulo" << std::endl;
        exit(1);
    }
    pJ->operator-=(danosidade ? danosidade : pJ->getVida());
    pJ->eliminar();
    ativo = false;
    corpo.setPosition(-100.f, -100.f);
}

}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
