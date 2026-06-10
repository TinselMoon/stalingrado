#include "Arame_farp.hpp"
#include "../Personagens/Jogador.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Obstaculos {

Arame_farp::Arame_farp() : Obstaculo(false, true, "Arame_farp"), fator_lentidao(0.4){
}

Arame_farp::~Arame_farp(){
}

void Arame_farp::executar(){

}

void Arame_farp::salvar(){
}

void Arame_farp::obstaculizar(Personagens::Jogador* pJ){
    pJ->setVelocidadeX(pJ->getVelX()*fator_lentidao);
    if(pJ->getVelY() > 0)
        pJ->setVelocidadeY(pJ->getVelY()*fator_lentidao);
}

}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
