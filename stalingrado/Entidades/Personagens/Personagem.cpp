#include "Personagem.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {

Personagem::Personagem() : Entidades::Entidade(){
    num_vidas = 0;
}

Personagem::Personagem(int vida) : Entidades::Entidade(){
    num_vidas = vida;
}

Personagem::~Personagem(){
    num_vidas = -1;
}
void Personagem::salvarDataBuffer(){

}

void Personagem::setNewPos(float x, float y){
    personagem.move(x, y);
}

void Personagem::setVelocidadeX(float vx){
    vel_x = vx;
}
void Personagem::setVelocidadeY(float vy){
    vel_y = vy;
}


}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
