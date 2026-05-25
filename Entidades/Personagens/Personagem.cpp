#include "Personagem.hpp"

namespace Entidades {
namespace Personagens {

Personagens::Personagem::Personagem() : Entidades::Entidade(){
    num_vidas = 0;
}

Personagens::Personagem::Personagem(int vida) : Entidades::Entidade(){
    num_vidas = vida;
}

void Personagens::Personagem::salvarDataBuffer(){

}

}
} // Fim dos namespaces
