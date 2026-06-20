#pragma once
#include "Fases/Fase_prim.hpp"
#include "Fases/Fase_seg.hpp"
#include "../Menus/Menu.hpp"
#include <SFML/Audio.hpp>

namespace Stalingrado {
    namespace States {
        //Aqui esta implementado o SINGLETON
        class Jogo {
        private:
            static Jogo* instanciaJogo;
            Gerenciadores::Gerenciador_Grafico GG;
            sf::Music musica;
            sf::Clock clock;
            sf::Time tempoDecorrido;
            static float dt;

            Menus::Menu* pMenuI;
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
        };
    }
}