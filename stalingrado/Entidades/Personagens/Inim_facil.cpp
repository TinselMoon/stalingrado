#include "Inim_facil.hpp"
#include "../../Jogo.hpp"
#include "Jogador.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

namespace Stalingrado {

namespace Entidades {
namespace Personagens {

Inim_facil::Inim_facil(int vida, int maldade) : Personagens::Inimigo(vida, maldade, "Inimigo_facil"), max_speed(300.f){

}

Inim_facil::~Inim_facil(){

}


void Inim_facil::danificar(Jogador *pJ){
    dt_dano += Jogo::getDt();
    if(dt_dano > 0.5f){
        pJ->tomarDano(nivel_maldade);
        dt_dano = 0;
    }
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
        setVelocidadeX(250.f*new_direction);
        if(rand() % 100 < 10 && getVelY() == 0)
            setVelocidadeY(-800.f);
        dt_movimento = 0;
    }
    Personagem::mover();
}
}
}
} // Fim do namespace Stalingrado
