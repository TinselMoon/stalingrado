#include "Personagem.hpp"

namespace Entidades {
namespace Personagens {

Personagem::Personagem() : Entidades::Entidade(){
    num_vidas = 0;
}

Personagem::Personagem(int vida) : Entidades::Entidade(){
    num_vidas = vida;
}

Personagem::~Personagem(){
    num_vidas = -1;
}
void Personagem::salvarDataBuffer(){

}

}
} // Fim dos namespaces
