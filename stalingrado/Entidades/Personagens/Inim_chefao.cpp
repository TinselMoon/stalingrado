#include "Inim_chefao.hpp"
#include "../../States/Jogo.hpp"
#include "Jogador.hpp"
#include "../Projetil.hpp"
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

// Offset do bico do canhao em relacao ao centro do sprite do tanque, calculado a
// partir do pixel da ponta do cano em tanque.png (0, 313.5 de um total de 2886x1203)
// e da escala de exibicao registrada em texturas.txt (738.2x324.2).
#define GUN_OFFSET_X -369.3f
#define GUN_OFFSET_Y -77.6f

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {
            using namespace States;

            Inim_chefao::Inim_chefao(int vida, int maldade) : Personagens::Inimigo(vida, maldade, "Inim_chefao"), id_chef(cont_chef++), proj_chefao(nullptr){
                max_speed = 050.f;
                isChefao = 1;
                dt_mudar_direcao = 2.f;
            }
            int Inim_chefao::cont_chef(0);

            Inim_chefao::~Inim_chefao(){

            }

            void Inim_chefao::executar(){
                mover();
            }
            void Inim_chefao::salvar(std::ofstream& arquivo){
                arquivo << id << " INIM_CHEFAO " << getVida()
                        << " " << getPos().x
                        << " " << getPos().y << "\n";
            }
            void Inim_chefao::mover(){
                dt_movimento += Jogo::getDt();
                if(dt_movimento > dt_mudar_direcao){
                    int new_direction = (rand() % 3) - 1;
                    setVelocidadeX(max_speed*new_direction);
                    //if(rand() % 100 < 10 && getVelY() == 0)
                    //setVelocidadeY(-800.f);
                    dt_movimento = 0;
                }
                Personagem::mover();
            }
            void Inim_chefao::setProjetil(Projetil* pP){
                proj_chefao = pP;
                pP->setChefao(this);
            }
            int Inim_chefao::getIdChef(){
                return id_chef;
            }
            void Inim_chefao::danificar(Personagem *pPers) {
                if (pPers==nullptr) {cerr << "Erro no Jogador(ponteiro nulo)" << endl; return;} //erro se o ponteiro for nulo
                dt_dano += Jogo::getDt(); //tempo de contato para tomar dano
                if (dt_dano > 5.0f) {
                    if(!(proj_chefao->isAtivo())){
                        sf::Vector2f posi_ini = corpo.getPosition();
                        posi_ini.x = posi_ini.x + GUN_OFFSET_X;
                        posi_ini.y = posi_ini.y + GUN_OFFSET_Y;
                        proj_chefao->setPosition(posi_ini.x, posi_ini.y);
                        sf::Vector2f posi_fin = pPers->getPos();
                        sf::Vector2f dist(posi_fin.x - posi_ini.x, posi_fin.y - posi_ini.y);
                        float module = sqrtf(dist.x*dist.x + dist.y*dist.y);
                        dist.x = dist.x/module;
                        dist.y = dist.y/module;
                        proj_chefao->setDir(dist.x, dist.y);
                        proj_chefao->ativar();

                        dt_dano = 0;
                    }
                }
            }
        }
    }
}
