#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <map>
#include <string>

//Criar singleton

namespace Stalingrado {
//Pré declaração do namespace aqui para usar os ponteiros e etc
class Ente;

namespace Gerenciadores {
class Gerenciador_Grafico {
private:
    sf::RenderWindow janela;
    sf::View camera;
    sf::Font font;
    Stalingrado::Ente *alvoCamera;
    std::map <std::string, std::pair<sf::Texture, sf::Vector2f> > mapa_texturas; // basta buscar pelo nome para usar a textura
public:
    Gerenciador_Grafico();
    ~Gerenciador_Grafico();

    void carregarTextura(const std::string& nome, const std::string& caminhoTextura, const sf::Vector2f tamanho, const bool isRepeated);
    void lerTexturas(const std::string& caminhoArquivo);

    const sf::Texture& getTextura(const std::string& nome);
    const sf::Vector2f getTamanhoTextura(const std::string& nome);

    void desenharEnte (Stalingrado::Ente *pE);
    void desenharTextoCoordAbs(const std::string& texto, int tam, float x, float y);
    void desenharTextoCamera(const std::string& texto, int tam, float x, float y);
    sf::RenderWindow* getJanela();   
    void executar();
    void setAlvoCamera(Stalingrado::Ente* pAlvo);
    void atualizarCamera();
};
}
}
