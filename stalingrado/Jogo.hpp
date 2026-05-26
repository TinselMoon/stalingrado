#pragma once
#include "Menu.hpp"

namespace Stalingrado{

    namespace Entidades{

        namespace Personagens{
            //Forward declaration para usar ponteiro
            class Jogador;
            class Inim_facil;

            class Jogo{
            private:
                Gerenciadores::Gerenciador_Grafico GG;
                Menu mJogo;
                Jogador* pJog1;
                Inim_facil* pInim1; //Implementação do Gustavo
            public:
                Jogo();
                ~Jogo();
                void executar();
            };
        }
    }
}
