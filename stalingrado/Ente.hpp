#pragma once
#include "Gerenciadores/Gerenciador_grafico.hpp"

namespace Stalingrado{

    class Ente {
    protected:
        int id;
        static int contId; //adicao do Gustavo, interpretacao
        static Gerenciadores::Gerenciador_Grafico* pGG;
        sf::Sprite corpo;

    public:
        Ente(const std::string& nomeTextura);
        Ente();
        virtual ~Ente();
        virtual void executar() = 0;
        void desenhar();
        static void setGG(Gerenciadores::Gerenciador_Grafico* pG);
        sf::FloatRect getRectangle();
        const sf::Sprite* getSprite();
    };

}
