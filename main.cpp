//#include "Stalingrad.hpp"

//using namespace Stalingrado;
#include <SFML/Graphics.hpp>

int main(void){
    /*Jogo jogo;
    jogo.executar();
    sf::RenderWindow janela(sf::VideoMode(800, 600), "Stalingrado");
    while (janela.isOpen()) { //loop 'infinito' para so fechar janela qnd apertar esc ou clicar no x
        sf::Event evento;
        while (janela.pollEvent(evento)) {
            if ((evento.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
                janela.close();
            }
        }
    }   //IMPLEMENTAR
    return 0;*/
    sf::RenderWindow window(sf::VideoMode(800, 600), "Teste SFML");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;

}
