#include "Inim_medio.hpp"
#include "../../Jogo.hpp"
#include "Jogador.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

namespace Stalingrado {

namespace Entidades {
namespace Personagens {

Inim_medio::Inim_medio(int vida, int maldade) : Personagens::Inimigo(vida, maldade, "Inimigo_medio"){
    max_speed = 350.f;
}

Inim_medio::~Inim_medio(){

}



void Inim_medio::executar(){
    mover();
}
void Inim_medio::salvar(){

}
void Inim_medio::mover(){
    dt_movimento += Jogo::getDt();
    if(dt_movimento > 1){
        int new_direction = (rand() % 3) - 1;
        setVelocidadeX(max_speed*new_direction);
        if(rand() % 100 < 10 && getVelY() == 0)
            setVelocidadeY(-800.f);
        dt_movimento = 0;
    }
    Personagem::mover();
}

void Inim_medio::danificar(Jogador *pJ) {

    //if (pJ==NULL) {cerr << "Erro no Jogador(ponteiro nulo)" << endl; exit(1);} //erro se so tiver o Jog1?

    if (pJ->getVida() - nivel_maldade >=0) {

        dt_dano += Jogo::getDt(); //tempo de contato para tomar dano
        if (dt_dano > 0.25f) {
            pJ->operator-=(nivel_maldade);
            dt_dano = 0;
        }

    }
}


}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
