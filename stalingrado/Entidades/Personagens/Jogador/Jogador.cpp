#include "Jogador.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {

Jogador::Jogador(int vida) : Personagem(vida){
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) y -= 5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) y += 5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) x -= 5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) x += 5;
}

void Jogador::desenhar(){
}

}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
