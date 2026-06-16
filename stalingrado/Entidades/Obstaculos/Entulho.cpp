#include "Entulho.hpp"

#include "../Personagens/Jogador.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Obstaculos {

Entulho::Entulho() : Obstaculo(false, false, "Entulho"){

    altura = this->getSprite()->getGlobalBounds().height;
}

Entulho::~Entulho(){

}

void Entulho::executar(){

}

void Entulho::salvar(){
}

void Entulho::obstaculizar(Personagens::Jogador* pJ){

    //se os jogadores colidirem lateralmente com o entulho eles serao levemente empurrados para tras
}

}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
