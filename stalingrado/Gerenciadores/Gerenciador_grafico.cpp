#include "Gerenciador_grafico.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>
#include "../Ente.hpp"

namespace Stalingrado {
using namespace Gerenciadores;

Gerenciador_Grafico::Gerenciador_Grafico(): janela(sf::VideoMode(1920, 1080), "Stalingrado", sf::Style::Fullscreen){
    janela.setFramerateLimit(60);
    camera.setSize(sf::Vector2f(1920.f, 1080.f)); 
    janela.setView(camera);
    //Carregar texturas para o hashmap aqui
    carregarTextura("Inimigo_facil", "../stalingrado/assets/soldado.png", sf::Vector2f(100.f, 174.0f));
    carregarTextura("Soldado", "../stalingrado/assets/sov.png", sf::Vector2f(100.0f, 150.0f));
    carregarTextura("Cachorro", "../stalingrado/assets/cachorro.png", sf::Vector2f(100.0f, 100.0f));
    carregarTextura("Inim_chefao", "../stalingrado/assets/tanque.png", sf::Vector2f(100.0f, 100.0f));
    carregarTextura("Chao_fase_um", "../stalingrado/assets/chao_fase_um.png", sf::Vector2f(1920.f, 900.f));
    carregarTextura("Cenario_fase_um", "../stalingrado/assets/cenario.png", sf::Vector2f(2172.f, 750.f));
    if (!font.loadFromFile("../stalingrado/assets/font.ttf")) {
        std::cerr << "Erro ao carregar a fonte!" << std::endl;
    }
}

Gerenciador_Grafico::~Gerenciador_Grafico(){
}

void Gerenciador_Grafico::carregarTextura(const std::string& nome, const std::string& caminhoArquivo, const sf::Vector2f tamanho) {
    sf::Texture textura;
    if (textura.loadFromFile(caminhoArquivo)) {
        mapa_texturas[nome].first = textura;
        if(nome == "Chao_fase_um" || nome == "Cenario_fase_um"){
            mapa_texturas[nome].first.setRepeated(true);
        }
        mapa_texturas[nome].second = tamanho;
    } 
}

void Gerenciador_Grafico::setAlvoCamera(Stalingrado::Ente* pAlvo) {
    alvoCamera = pAlvo;
}

void Gerenciador_Grafico::atualizarCamera() {
    if (alvoCamera != NULL) {
            sf::Vector2f posAlvo = alvoCamera->getSprite()->getPosition();
        
        if(posAlvo.x < 1920.f/2){
            camera.setCenter(1920.f/2, 540.f);
        }
        else if(posAlvo.x > (10000 - 1920.f/2)){
            camera.setCenter(10000 - 1920.f/2, 540.f);
        }
        else{
            camera.setCenter(posAlvo.x, 540.f);
        }
        
        janela.setView(camera);
    }
}

void Gerenciador_Grafico::desenharTextoCoordAbs(const std::string& texto, int tam, float x, float y){
    sf::Text text;
    text.setFont(font);
    text.setString(texto);
    text.setCharacterSize(tam);
    text.setPosition(x, y);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(3.f);
    janela.draw(text);
}

void Gerenciador_Grafico::desenharTextoCamera(const std::string& texto, int tam, float x, float y){
    sf::Text text;
    text.setFont(font);
    text.setString(texto);
    text.setCharacterSize(tam);
    text.setPosition(x, y);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(3.f);
    janela.setView(janela.getDefaultView());
    janela.draw(text);
    janela.setView(camera);
}

const sf::Texture& Gerenciador_Grafico::getTextura(const std::string& nome) {
    return mapa_texturas[nome].first;
}

const sf::Vector2f Gerenciador_Grafico::getTamanhoTextura(const std::string& nome) {
    return mapa_texturas[nome].second; // Retorna o Vector2f salvo no pair
}

void Gerenciador_Grafico::desenharEnte(Ente *pE){
    if(pE != NULL)
        janela.draw(*(pE->getSprite()));
}


sf::RenderWindow* Gerenciador_Grafico::getJanela(){
    return &janela;
}

} // Fim do namespace Stalingrado
