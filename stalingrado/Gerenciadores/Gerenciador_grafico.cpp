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
    carregarTextura("Inimigo_facil", "../stalingrado/assets/solado.png", sf::Vector2f(100.0f, 100.0f));
    carregarTextura("Soldado", "../stalingrado/assets/sov.png", sf::Vector2f(100.0f, 100.0f));
    carregarTextura("Cachorro", "../stalingrado/assets/cachorro.png", sf::Vector2f(100.0f, 100.0f));
    carregarTextura("Inim_chefao", "../stalingrado/assets/tanque.png", sf::Vector2f(100.0f, 100.0f));
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
    return mapa_texturas[nome].first;
}

const sf::Vector2f Gerenciador_Grafico::getTamanhoTextura(const std::string& nome) {
    return mapa_texturas[nome].second; // Retorna o Vector2f salvo no pair
}

void Gerenciador_Grafico::desenharEnte(Ente *pE){
    if(pE != NULL)
        janela.draw(pE->getSprite());
}


sf::RenderWindow* Gerenciador_Grafico::getJanela(){
    return &janela;
}

} // Fim do namespace Stalingrado
