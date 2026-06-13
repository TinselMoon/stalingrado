#include "Inim_chefao.hpp"
#include "../../Jogo.hpp"
#include "Jogador.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

namespace Stalingrado {
    namespace Entidades {
        namespace Personagens {

            Inim_chefao::Inim_chefao(int vida, int maldade) : Personagens::Inimigo(vida, maldade, "Inim_chefao"){
                max_speed = 050.f;
            }

            Inim_chefao::~Inim_chefao(){

            }

            void Inim_chefao::executar(){
                mover();
            }
            void Inim_chefao::salvar(){

            }
            void Inim_chefao::mover(){
                dt_movimento += Jogo::getDt();
                if(dt_movimento > 1){
                    int new_direction = (rand() % 3) - 1;
                    setVelocidadeX(max_speed*new_direction);
                    //if(rand() % 100 < 10 && getVelY() == 0)
                    //setVelocidadeY(-800.f);
                    dt_movimento = 0;
                }
                Personagem::mover();
            }

            void Inim_chefao::danificar(Jogador *pJ) {
                if (pJ==NULL) {cerr << "Erro no Jogador(ponteiro nulo)" << endl; exit(1);} //erro se so tiver o Jog1?

                dt_dano += Jogo::getDt(); //tempo de contato para tomar dano
                if (dt_dano > 0.2f) {
                    pJ->operator-=(nivel_maldade);
                    dt_dano = 0;
                }
            }
        }
    }
}
