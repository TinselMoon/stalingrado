#pragma once
#include "Personagem.hpp"
#include <SFML/Graphics.hpp>

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {

            class Inimigo;
            class Jogador : public Personagem {
            private:
                bool WisPressed;
                bool belicoso;
                static int cont_jog;
                int id_jog;
                float multiplicador_vel;
                float cooldown_mov;
            protected:
                int pontos;
            public:
                Jogador(int vida = 0);
                ~Jogador();
                void lerMovimentacao();
                void executar();
                void salvar();
                bool getBelicoso() const;
                void setBelicoso(bool belico);
                void mover();
                void danificar (Personagem* pPers);
                void setMultiplicadorVel(float mult);
                const int getPontos() const{return pontos;}
                void impulso(float mult);
                void setCooldown(float cd);
            };
        }
    }
}
