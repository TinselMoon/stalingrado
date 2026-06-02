#include "Inim_facil.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {

Inim_facil::Inim_facil(int vida, int maldade) : Personagens::Inimigo(vida, maldade, "Inimigo_facil"){
}

Inim_facil::~Inim_facil(){

}


void Inim_facil::danificar(Jogador *pJ){

}
void Inim_facil::executar(){
    mover();
}
void Inim_facil::salvar(){

}
void Inim_facil::mover(){
    sf::Vector2f posi = personagem.getPosition();
    personagem.setPosition(posi.x +1, posi.y + 1);

}
/*
void Inim_facil::desenhar(){
}
*/
}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
