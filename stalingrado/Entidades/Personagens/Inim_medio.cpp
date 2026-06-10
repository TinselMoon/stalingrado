#include "Inim_medio.hpp"
#include "../../Jogo.hpp"
#include "Jogador.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {

Inim_medio::Inim_medio(int vida, int maldade) : Personagens::Inimigo(vida, maldade, "Inimigo_medio"){
    max_speed = 500.f;
}

Inim_medio::~Inim_medio(){

}


void Inim_medio::danificar(Jogador *pJ){

    if (pJ->getVida()>=2) {
        dt_dano += Jogo::getDt();
        if(dt_dano > 0.5f){
            pJ->tomarDano(nivel_maldade);
            dt_dano = 0;
        }
    }
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

}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
