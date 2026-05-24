#include "Gerenciador_grafico.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace Gerenciadores;

Gerenciador_Grafico::Gerenciador_Grafico(){
    janela = new sf::RenderWindow(sf::VideoMode(800, 600), "Stalingrado");
}

Gerenciador_Grafico::~Gerenciador_Grafico(){
    delete janela;
    janela = NULL;
}

void Gerenciador_Grafico::desenhar(sf::RectangleShape* forma){
    if (forma != NULL) {
        janela->draw(*forma);
    }
}

sf::RenderWindow* Gerenciador_Grafico::getJanela(){
    return janela;
}
