#include "principal.hpp"

Stalingrado::Principal::Principal() :
    window(sf::VideoMode(1920.0f, 1080.0f),"Stalingrado", sf::Style::Fullscreen)
{


    executar();
}

Stalingrado::Principal::~Principal() {


}

void Stalingrado::Principal::executar() {

    sf::RectangleShape jogador(sf::Vector2f(100.0f, 100.0f));
    jogador.setFillColor(sf::Color::Red);
    jogador.setPosition(sf::Vector2f(860.0f, 440.0f));

    while (window.isOpen()) {
        sf::Event evento;
        if (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                window.close();
            else if (evento.type == sf::Event::KeyPressed) {
                if (evento.key.code == sf::Keyboard::Escape)
                    window.close  ();
            }
        }
        window.clear();
        window.draw(jogador);
        window.display();
    }

}
