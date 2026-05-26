#include "Inimigo.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {

Inimigo::Inimigo(int vida, int maldade) : Personagens::Personagem(vida){
    nivel_maldade = maldade;
}

Inimigo::Inimigo() : Personagens::Personagem(){
}

Inimigo::~Inimigo(){
    nivel_maldade = -1;
}

void Inimigo::salvarDataBuffer(){

}


}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
