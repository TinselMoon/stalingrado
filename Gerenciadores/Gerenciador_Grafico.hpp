#pragma once

#include <SFML/Graphics.hpp>

namespace Stalingrado {

    class Ente;

    namespace Gerenciadores {

        class Gerenciador_Grafico {

        private:
            sf::RenderWindow Obj; //interpretacao do Gustavo sobre o atributo da classe no UML

        public:
            Gerenciador_Grafico();
            ~Gerenciador_Grafico();
            void desenharEnte (Ente *pE);
            void executar(); //interpretacao Gustavo
        };

    }

}