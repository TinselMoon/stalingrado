#include "Obstaculo.hpp"

namespace Entidades {
namespace Obstaculos {

Obstaculo::Obstaculo() : Entidades::Entidade(){
    danoso = false;
    lentidao = false;
}


Obstaculo::Obstaculo(bool dano, bool lento) : Entidades::Entidade(){
    danoso = dano;
    lentidao = lento;
}

Obstaculo::~Obstaculo(){
    danoso = false;
}

void Obstaculo::salvarDataBuffer(){

}

}
} // Fim dos namespaces
