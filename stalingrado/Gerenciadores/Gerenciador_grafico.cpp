#include "Gerenciador_grafico.hpp"

#include <fstream>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>
#include "../Ente.hpp"

namespace Stalingrado {

    using namespace Gerenciadores;

    Gerenciador_Grafico::Gerenciador_Grafico(): janela(sf::VideoMode(1920, 1080), "Stalingrado", sf::Style::Fullscreen) {
            janela.setFramerateLimit(600);
            camera.setSize(sf::Vector2f(1920.f, 1080.f));
            janela.setView(camera);
            lerTexturas("../stalingrado/assets/texturas.txt");
            if (!font.loadFromFile("../stalingrado/assets/font.ttf"))
            std::cerr << "Erro ao carregar a fonte!" << std::endl;
    }

    Gerenciador_Grafico::~Gerenciador_Grafico(){
    }

    const sf::Font& Gerenciador_Grafico::getFont() {
        return font;
    }

    void Gerenciador_Grafico::carregarTextura(const std::string& nome, const std::string& caminhoTextura, const sf::Vector2f tamanho, const bool isRepeated) {

        if (mapa_texturas[nome].first.loadFromFile(caminhoTextura)) {
            mapa_texturas[nome].first.setRepeated(isRepeated);
            mapa_texturas[nome].second = tamanho;
        }

        else
            std::cerr << "Nao foi possivel carregar: " << caminhoTextura << std::endl;

    }
    void Gerenciador_Grafico::lerTexturas(const std::string& caminhoArquivo) {

        std::ifstream arquivo (caminhoArquivo.c_str());

        if (!arquivo.is_open()) {std::cerr << "Nao foi possivel abrir arquivos das texturas" << std::endl; exit(1);}

        std::string nome;
        std::string caminhoTextura;
        float x;
        float y;
        bool isRepeated;

        while (arquivo >> nome >> caminhoTextura >> x >> y >> isRepeated)
            Gerenciador_Grafico::carregarTextura(nome, caminhoTextura, sf::Vector2f(x,y), isRepeated);

        arquivo.close();
    }

    void Gerenciador_Grafico::setAlvoCamera(Stalingrado::Ente* pAlvo) {
        alvoCamera = pAlvo;
    }

    void Gerenciador_Grafico::atualizarCamera() {
        if (alvoCamera != nullptr) {
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

    void Gerenciador_Grafico::usarCameraJogo() {
        janela.setView(camera);
    }

    void Gerenciador_Grafico::usarViewPadrao() {
        janela.setView(janela.getDefaultView());
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
        if(pE != nullptr)
            janela.draw(*(pE->getSprite()));
    }

    void Gerenciador_Grafico::desenharTexto(const sf::Text& texto){
        janela.draw(texto);
    }

    sf::RenderWindow* Gerenciador_Grafico::getJanela(){
        return &janela;
    }
} // Fim do namespace Stalingrado
