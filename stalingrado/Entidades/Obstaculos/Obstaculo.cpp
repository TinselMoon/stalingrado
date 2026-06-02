#include "Obstaculo.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Obstaculos {


Obstaculo::Obstaculo(bool dano, bool lento, const std::string& nomeTextura) : Entidade(nomeTextura){
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
