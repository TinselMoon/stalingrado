#include "Inim_chefao.hpp"
#include "../../States/Jogo.hpp"
#include "Jogador.hpp"
#include "../Projetil.hpp"
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

#include "../../Defines.hpp"

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
                        << " " << getPos().y
                        << " " << getVelX();
                if(proj_chefao != nullptr){
                    arquivo << " " << proj_chefao->isAtivo()
                            << " " << proj_chefao->getPosition().x
                            << " " << proj_chefao->getPosition().y
                            << " " << proj_chefao->getVelX()
                            << " " << proj_chefao->getVelY()
                            << " " << proj_chefao->getDtExist();
                }
                else{
                    arquivo << " 0 -100 -100 0 0 0";
                }
                arquivo << "\n";
            }
            void Inim_chefao::aplicarVelocidadeSalva(float vx){
                setVelocidadeX(vx);
            }
            void Inim_chefao::restaurarProjetil(bool ativo, float x, float y, float vx, float vy, float dtExist){
                if(proj_chefao != nullptr){
                    proj_chefao->restaurarEstado(ativo, x, y, vx, vy, dtExist);
                }
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
