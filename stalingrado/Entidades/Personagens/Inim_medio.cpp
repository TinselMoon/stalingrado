#include "Inim_medio.hpp"
#include "../../States/Jogo.hpp"
#include "Jogador.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {
            using namespace States;

            Inim_medio::Inim_medio(int vida, int maldade) : Personagens::Inimigo(vida, maldade, "Inimigo_medio"),
            recover_life(rand() % 10 + 10)
            {
                max_speed = 350.f;
                isChefao = 0;
                dt_mudar_direcao = 0.5f;
            }

            Inim_medio::~Inim_medio(){

            }

            void Inim_medio::executar(){
                mover();
            }
            void Inim_medio::salvar(){

            }
            void Inim_medio::mover(){
                float velAntiga = getVelX();
                float velAtual = 0;
                dt_movimento += Jogo::getDt();
                if(dt_movimento > dt_mudar_direcao){
                    int new_direction = (rand() % 3) - 1;
                    velAtual = max_speed*new_direction;
                    setVelocidadeX(velAtual);
                    if(rand() % 100 < 10 && getVelY() == 0)
                        setVelocidadeY(-400.f);
                    dt_movimento = 0;
                    if(velAtual != 0 && velAntiga != velAtual){
                        //Atualizar lado que o personagem esta olhando
                        int larguraTextura = corpo.getTexture()->getSize().x;
                        int alturaTextura = corpo.getTexture()->getSize().y;
                        if(velAtual > 0){
                            corpo.setTextureRect(sf::IntRect(0, 0, larguraTextura, alturaTextura));
                        }
                        if(velAtual < 0){
                            corpo.setTextureRect(sf::IntRect(larguraTextura, 0,-larguraTextura, alturaTextura));
                        }
                    }
                }
                Personagem::mover();
            }

            void Inim_medio::danificar(Personagem* pPers) {

                if (pPers==nullptr) {cerr << "Erro no Jogador(ponteiro nulo)" << endl; exit(1);} //erro se so tiver o Jog1?

                dt_dano += Jogo::getDt(); //tempo de contato para tomar dano
                if (dt_dano > 0.35f) {
                    *pPers -= nivel_maldade;
                    if(pPers->getVida() == 0){
                        pPers->eliminar();
                    }
                    dt_dano = 0;
                }
            }
        }
    }
}
