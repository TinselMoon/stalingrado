#include "Jogador.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {

Jogador::Jogador(int vida) : Personagem(vida, "Soldado"){
    pontos = 0;
}
Jogador::~Jogador(){
    pontos = -1;
}

void Jogador::colidir(Inimigo* pIn){

}

void Jogador::executar(){
    mover();
}

void Jogador::salvar(){

}

void Jogador::mover(){
    //MUDAR AGORA QUE USAMOS SPRITE
    sf::Vector2f posi = personagem.getPosition();
    personagem.setPosition(posi.x +1, posi.y + 1);
}
/*
void Jogador::desenhar(){
}
*/
}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
