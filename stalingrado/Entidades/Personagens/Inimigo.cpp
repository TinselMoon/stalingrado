#include "Inimigo.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {

Inimigo::Inimigo(int vida, int maldade, const std::string& nomeTextura) : Personagens::Personagem(vida, nomeTextura){
    nivel_maldade = maldade;
}

Inimigo::~Inimigo(){
    nivel_maldade = -1;
}

void Inimigo::salvarDataBuffer(){

}

void Inimigo::salvar(){

}

void Inimigo::mover(){

}


}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
