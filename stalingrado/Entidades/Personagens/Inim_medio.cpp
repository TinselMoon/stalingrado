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
                Inimigo::mover();
            }
            void Inim_medio::salvar(std::ofstream& arquivo){
                arquivo << id << " INIM_MEDIO " << getVida()
                        << " " << getPos().x
                        << " " << getPos().y
                        << " " << getVelX() << "\n";
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
