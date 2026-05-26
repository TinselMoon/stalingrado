#include "Obstaculo.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Obstaculos {

Obstaculo::Obstaculo() : Entidade(){
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

} // Fim do namespace Stalingrado
