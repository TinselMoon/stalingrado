#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.hpp"


namespace Stalingrado {

    using namespace Gerenciadores;

        class Ente {

        protected:
            int id;
            static int contId; //adicao do Gustavo, interpretacao
            static Gerenciador_Grafico* pGG;
            sf::RectangleShape* pFig; //interpretacao do Gustavo sobre o UML

        public:
            Ente();
            virtual ~Ente();
            virtual void executar() = 0;
            void desenhar ();
            static void setGG (Gerenciador_Grafico* pGG);
        };
    }

