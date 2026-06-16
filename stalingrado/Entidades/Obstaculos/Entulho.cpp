#include "Entulho.hpp"

#include "../Personagens/Jogador.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Obstaculos {

Entulho::Entulho() : Obstaculo(false, false, "Entulho"){

    altura = this->getRectangle().getPosition().y;
}

Entulho::~Entulho(){

}

void Entulho::executar(){

}

void Entulho::salvar(){
}

void Entulho::obstaculizar(Personagens::Jogador* pJ){

    if (pJ->getRectangle().getPosition().y > altura)
        pJ->operator-=(1);

}

}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
