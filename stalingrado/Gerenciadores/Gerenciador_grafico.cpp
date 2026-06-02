#include "Gerenciador_grafico.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "../Ente.hpp"

namespace Stalingrado {
using namespace Gerenciadores;

Gerenciador_Grafico::Gerenciador_Grafico(): janela(sf::VideoMode(1920, 1080), "Stalingrado", sf::Style::Fullscreen){
    janela.setFramerateLimit(60);
    //Carregar texturas para o hashmap aqui
}

Gerenciador_Grafico::~Gerenciador_Grafico(){
}

void Gerenciador_Grafico::carregarTextura(const std::string& nome, const std::string& caminhoArquivo, const sf::Vector2f tamanho) {
    sf::Texture textura;
    if (textura.loadFromFile(caminhoArquivo)) {
        mapa_texturas[nome].first = textura; 
        mapa_texturas[nome].second = tamanho;
    } 
}

const sf::Texture& Gerenciador_Grafico::getTextura(const std::string& nome) {
    return mapa_texturas[nome];
}

void Gerenciador_Grafico::desenharEnte(Ente *pE){
    if(pE != NULL)
        janela.draw(pE->getSprite());
}


sf::RenderWindow* Gerenciador_Grafico::getJanela(){
    return &janela;
}

} // Fim do namespace Stalingrado
