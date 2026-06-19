#pragma once
#include "Gerenciador_input.hpp"
#include "Gerenciador_grafico.hpp"

namespace Stalingrado {
    namespace Gerenciadores {

        class Gerenciador_eventos {
        private:
            Graphics* pGG;
            Input* pInputM;
            sf::RenderWindow* pWindow;

            static Gerenciador_eventos* instance;
            Gerenciador_eventos();

        public:
            ~Gerenciador_eventos();

            static Gerenciador_eventos* getInstance();

            void setGraphicManager();
            void setInput(Input* pIM);

            void pollEvents();
        };

    }
}