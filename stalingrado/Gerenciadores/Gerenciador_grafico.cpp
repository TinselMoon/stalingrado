#include "Gerenciador_grafico.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "../Ente.hpp"

namespace Stalingrado {
using namespace Gerenciadores;

Gerenciador_Grafico::Gerenciador_Grafico(): janela(sf::VideoMode(1920, 1080), "Stalingrado", sf::Style::Fullscreen){
    janela.setFramerateLimit(60);
}

Gerenciador_Grafico::~Gerenciador_Grafico(){
}

void Gerenciador_Grafico::carregarTextura(const std::string& nome, const std::string& caminhoArquivo) {
    sf::Texture textura;
    if (textura.loadFromFile(caminhoArquivo)) {
        // Se carregou com sucesso, salva no mapa com o nome escolhido
        mapa_texturas[nome] = textura; 
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
