#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <map>
#include <string>

namespace Stalingrado {
//Pré declaração do namespace aqui para usar os ponteiros e etc
    class Ente;

    namespace Gerenciadores {
    class Gerenciador_Grafico {
    private:
        sf::RenderWindow janela;
        std::map<std::string, std::pair<sf::Texture, sf::RectangleShape> > mapa_texturas; // basta buscar pelo nome para usar a textura
    public:
        Gerenciador_Grafico();
        ~Gerenciador_Grafico();

        void carregarTextura(const std::string& nome, const std::string& caminhoArquivo, const sf::Vector2f tamanho);
        const sf::Texture& getTextura(const std::string& nome);
        const sf::Vector2f getRectangleShape(const std::string& nome);

        void desenharEnte (Stalingrado::Ente *pE);
        sf::RenderWindow* getJanela();   
        void executar(); //interpretacao Gustavo
    };
    }
}
