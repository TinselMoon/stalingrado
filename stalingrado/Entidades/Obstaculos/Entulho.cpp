#include "Entulho.hpp"

#include "../Personagens/Jogador.hpp"
#include <iostream>
using namespace std;

namespace Stalingrado {

namespace Entidades {
namespace Obstaculos {

Entulho::Entulho() : Obstaculo(false, false, "Entulho"){

    //altura = this->getSprite()->getGlobalBounds().height;
}

Entulho::~Entulho(){

}

void Entulho::executar(){

}

void Entulho::salvar(){
}

void Entulho::obstaculizar(Personagens::Jogador* pJ){

    //se os jogadores colidirem lateralmente com o entulho eles serao levemente empurrados para tras
    pJ->setCoolDown(0.5f);
    pJ->setVelocidadeX(-(pJ->getVelX()*0.6));
    pJ->setVelocidadeY(-300.f);
}

}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
