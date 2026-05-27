#include "Gerenciador_grafico.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/WindowStyle.hpp>

namespace Stalingrado {
using namespace Gerenciadores;

Gerenciador_Grafico::Gerenciador_Grafico(): janela(sf::VideoMode(1920, 1080), "Stalingrado", sf::Style::Fullscreen){
    janela.setFramerateLimit(60);
}

Gerenciador_Grafico::~Gerenciador_Grafico(){
}

void Gerenciador_Grafico::desenhar(sf::RectangleShape* forma){
    if (forma != NULL) {
        janela.draw(*forma);
    }
}

sf::RenderWindow* Gerenciador_Grafico::getJanela(){
    return &janela;
}

} // Fim do namespace Stalingrado
