#include "Jogador.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {

Jogador::Jogador(int vida) : Personagem(vida){
    pontos = 0;
    x = 100;
    y = 300;
    corpo.setSize(sf::Vector2f(100.f, 100.f));
    corpo.setPosition((float)x, (float)y);

    if (!textura.loadFromFile("../stalingrado/assets/soldado.png")) {
        corpo.setFillColor(sf::Color::Red);
    } else {
        corpo.setTexture(&textura);
    }
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
    corpo.setPosition((float)x, (float)y);
}

void Jogador::desenhar(){
    if (pGG != NULL) {
        pGG->desenhar(&corpo);
    }
}

}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
