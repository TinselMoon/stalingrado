#include "Projetil.hpp"
#include "../Jogo.hpp"

namespace Stalingrado {

namespace Entidades{

Projetil::Projetil() : Entidade("Projetil"), ativo(false), vel_x(0), vel_y(0), vel_projetil(250.f){

}

Projetil::~Projetil(){

}


void Projetil::setPosition(float x, float y){

}

void Projetil::ativar(){
    ativo = true;
}
void Projetil::destruir(){
    ativo = false;
    personagem.setPosition(-100.f,0.f);
}
void Projetil::executar(){
    if(ativo){
        float dx = 0, dy = 0, dt = 0;
        dt = Jogo::getDt();
        vel_y = vel_y + 200.f*dt;
        dx = vel_x*dt;
        dy = vel_y*dt;
        movePos(dx, dy);
    }
}
void Projetil::salvar(){

}
const bool Projetil::isAtivo() const{
    return ativo;
}
void Projetil::movePos(float x, float y){
    personagem.move(x, y);
}

void Projetil::setDir(float x, float y){
    vel_x = vel_projetil*x;
    vel_y = vel_projetil*y;
}
}//Fim namespace 

} // Fim do namespace Stalingrado
