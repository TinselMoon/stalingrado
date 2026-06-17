#include "Inim_facil.hpp"
#include "../../Jogo.hpp"
#include "Jogador.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

namespace Stalingrado {

namespace Entidades {
namespace Personagens {

Inim_facil::Inim_facil(int vida, int maldade) : Inimigo(vida, maldade, "Inimigo_facil"){
    max_speed = 250.f;
    isChefao = 0;
    mult_impulso = ((float)rand()/RAND_MAX)*0.5f + 0.4f;
}

Inim_facil::~Inim_facil(){

}

void Inim_facil::executar(){
    mover();
}
void Inim_facil::salvar(){

}
void Inim_facil::mover(){
    dt_movimento += Jogo::getDt();
    if(dt_movimento > 1){
        int new_direction = (rand() % 3) - 1;
        setVelocidadeX(max_speed*new_direction);
        if(rand() % 100 < 10 && getVelY() == 0)
            setVelocidadeY(-400.f);
        dt_movimento = 0;
    }
    Personagem::mover();
}

void Inim_facil::danificar(Personagem* pPers) {

    if (pPers==NULL) {cerr << "Erro no Personagem(ponteiro nulo)" << endl; exit(1);}

    dt_dano += Jogo::getDt(); //tempo de contato para tomar dano
    if (dt_dano > 0.25f) {
        *pPers -= nivel_maldade;
        if(pPers->getVida() == 0){
            pPers->eliminar();
        }
        else{
            Jogador *pJ = dynamic_cast<Jogador*>(pPers);
            pJ->impulso(mult_impulso);
        }
        dt_dano = 0;
    }
}

}
}
} // Fim do namespace Stalingrado
