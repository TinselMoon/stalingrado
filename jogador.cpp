#include "/home/x/Desktop/stalingrad/jogador.hpp"

#include <SFML/Window/Keyboard.hpp>

Stalingrado::Jogador::Jogador::~Jogador() {


}

void Stalingrado::Jogador::Jogador::inicializa() {
    vel = sf::Vector2f(0.1f, 0.1f);
}

const sf::RectangleShape Stalingrado::Jogador::getCorpo() const {

    return corpo;
}

void Stalingrado::Jogador::Jogador::move() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

        corpo.move(vel, b);
    }


}