#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <string>

namespace Stalingrado {
//Pré declaração do namespace aqui para usar os ponteiros e etc
    class Ente;

    namespace Gerenciadores {
    class Gerenciador_Grafico {
    private:
        sf::RenderWindow janela;
        std::map<std::string, sf::Texture> mapa_texturas; // basta buscar pelo nome para usar a textura
    public:
        Gerenciador_Grafico();
        ~Gerenciador_Grafico();

        void carregarTextura(const std::string& nome, const std::string& caminhoArquivo);
        const sf::Texture& getTextura(const std::string& nome);

        void desenharEnte (Stalingrado::Ente *pE);
        sf::RenderWindow* getJanela();   
        void executar(); //interpretacao Gustavo
    };
    }
}
