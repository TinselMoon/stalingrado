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
                int checkpoint_pontos;
                int dano;
                bool olhandoEsquerda;
                const sf::Texture* texturaIdle;
                const sf::Texture* texturaAtaque;
                sf::Vector2f tamanhoIdle;
                sf::Vector2f tamanhoAtaque;
                void aplicarTexturaAtaque();
            protected:
                int pontos;
            public:
                Jogador(int vida = 0);
                ~Jogador();
                void lerMovimentacao();
                void executar();
                void salvar(std::ofstream& arquivo);
                bool getBelicoso() const;
                void setBelicoso(bool belico);
                void mover();
                void danificar (Personagem* pPers);
                void setMultiplicadorVel(float mult);
                const int getPontos() const;
                void impulso(float mult);
                void setCooldown(float cd);
                int getUltimoCheckpoint();
                void setUltimoCheckpoint(int pontos);
            };

        }
    }
}
