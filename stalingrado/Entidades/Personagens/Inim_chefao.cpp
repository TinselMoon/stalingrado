#include "Inim_chefao.hpp"
#include "../../Jogo.hpp"
#include "Jogador.hpp"
#include "../Projetil.hpp"
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {
            Inim_chefao::Inim_chefao(int vida, int maldade) : Inimigo(vida, maldade, "Inim_chefao"), id_chef(cont_chef++), proj_chefao(NULL){
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
                if (pPers==NULL) {cerr << "Erro no Jogador(ponteiro nulo)" << endl; return;} //erro se o ponteiro for nulo
                dt_dano += Jogo::getDt(); //tempo de contato para tomar dano
                if (dt_dano > 5.0f) {
                    if(!(proj_chefao->isAtivo())){
                        sf::Vector2f posi_ini = personagem.getPosition();
                        posi_ini.x = posi_ini.x - 678.f;
                        posi_ini.y = posi_ini.y - 150.f;
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
