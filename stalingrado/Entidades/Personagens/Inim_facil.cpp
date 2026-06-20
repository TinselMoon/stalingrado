#include "Inim_facil.hpp"
#include "../../States/Jogo.hpp"
#include "Jogador.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {
            using namespace States;

            Inim_facil::Inim_facil(int vida, int maldade) : Personagens::Inimigo(vida, maldade, "Inimigo_facil"){
                max_speed = 250.f;
                isChefao = 0;
                tempo_atordoar = ((float)rand()/RAND_MAX)*0.4f + 0.4f;
                dt_mudar_direcao = 1.f;
            }

            Inim_facil::~Inim_facil(){

            }

            void Inim_facil::executar(){
                mover();
            }
            void Inim_facil::salvar(){

            }

            void Inim_facil::mover(){
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

            void Inim_facil::danificar(Personagem* pPers) {

                if (pPers==nullptr) {cerr << "Erro no Personagem(ponteiro nulo)" << endl; exit(1);}

                dt_dano += Jogo::getDt(); //tempo de contato para tomar dano
                if (dt_dano > 1.f) {
                    *pPers -= nivel_maldade;
                    if(pPers->getVida() == 0){
                        pPers->eliminar();
                    }
                    else{
                        Jogador *pJ = dynamic_cast<Jogador*>(pPers);
                        pJ->setVelocidadeX(0.f);
                        pJ->setCooldown(tempo_atordoar);
                    }
                    dt_dano = 0;
                }
            }
        }
    }
}
