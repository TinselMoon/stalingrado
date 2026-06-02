#pragma once
#include "Gerenciadores/Gerenciador_grafico.hpp"

namespace Stalingrado{
    class Ente {
    protected:
        int id;
        static int contId; //adicao do Gustavo, interpretacao
        static Gerenciadores::Gerenciador_Grafico* pGG;
        //A classe Sprite possui a posição do sprite também
        sf::Sprite personagem; //Melhorar o nome para englobar
        sf::RectangleShape actual_shape;
        sf::Texture* pFig; //ponteiro para a classe com o sprite

    public:
        Ente(const std::string& nomeTextura);
        Ente();
        virtual ~Ente();
        virtual void executar() = 0;
        void desenhar();
        static void setGG(Gerenciadores::Gerenciador_Grafico* pG);
        sf::FloatRect getRectangle();
        const sf::Sprite& getSprite();
    };
}
