#include "Entulho.hpp"

#include "../Personagens/Jogador.hpp"
#include <cstdlib>
using namespace std;

namespace Stalingrado {

namespace Entidades {
namespace Obstaculos {

Entulho::Entulho() : Obstaculo(false, false, "Entulho"), mult_impulso((float)(rand() % 51)/100 + 0.4f){

}

Entulho::~Entulho(){

}

void Entulho::executar(){

}

void Entulho::salvar(){

}

void Entulho::obstaculizar(Personagens::Jogador* pJ){

    //se os jogadores colidirem lateralmente com o entulho eles serao levemente empurrados para tras
    pJ->impulso(mult_impulso);
}

}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
