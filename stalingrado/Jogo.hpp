#pragma once
#include "Fases/Fase_prim.hpp"
#include "Menu.hpp"

namespace Stalingrado{

    namespace Entidades{

        namespace Personagens{
        //Forward declaration para usar ponteiro
        class Jogador;
        class Inim_facil;
        }
    }

    class Jogo{
    private:
        Gerenciadores::Gerenciador_Grafico GG;
        Menu mJogo;
        Fases::Fase_prim fase_um;
    public:
        Jogo();
        ~Jogo();
        void executar();
    };
}
