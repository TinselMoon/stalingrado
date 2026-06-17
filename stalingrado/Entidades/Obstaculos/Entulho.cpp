#include "Entulho.hpp"

#include "../Personagens/Jogador.hpp"
#include <cstdlib>
using namespace std;

namespace Stalingrado {

namespace Entidades {
namespace Obstaculos {

Entulho::Entulho() : Obstaculo(false, false, "Entulho"){
    mult_impulso = ((float)rand()/RAND_MAX)*(0.9f - 0.4f) + 0.4f;
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
    pJ->setVelocidadeX(-(pJ->getVelX()*mult_impulso));
    pJ->setVelocidadeY(-300.f);
}

}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
