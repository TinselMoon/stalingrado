#pragma once
#include "Fases/Fase_prim.hpp"
#include "Fases/Fase_seg.hpp"
#include "Menu.hpp"
#include <string>

namespace Stalingrado {

    namespace Entidades {
        namespace Personagens {
            class Jogador;
            class Inim_facil;
        }
    }
    //Aqui esta implementado o SINGLETON
    class Jogo {
    private:
        static Jogo* instanciaJogo;
        Gerenciadores::Gerenciador_Grafico GG;
        sf::Clock clock;
        sf::Time tempoDecorrido;
        static float dt;

        Menu* pMenu;
        Entidades::Personagens::Jogador* pJog1;
        Entidades::Personagens::Jogador* pJog2;
        Fases::Fase_prim* fase_um;
        Fases::Fase_seg* fase_seg;

        bool executando;
        int faseAtual;

        Jogo();

    public:
        ~Jogo();
        static Jogo* getInstanciaJogo();
        void executar();
        static float getDt();

        void iniciarFase1();
        void iniciarFase2();
        void fecharJogo();
        void salvarJogo(const std::string& caminho = "save.txt");

    };
}
