#include "Projetil.hpp"
#include "../Jogo.hpp"
#include "Personagens/Jogador.hpp"
#include "Personagens/Inim_chefao.hpp"

namespace Stalingrado {

namespace Entidades{

Projetil::Projetil() : Entidade("Projetil"), vel_x(0), vel_y(0), vel_projetil(500.f), dt_exist(0){
    ativo = false;
    personagem.setPosition(-100.f, -100.f);
}

Projetil::~Projetil(){

}

void Projetil::danificar(Personagens::Jogador *pJ){
    *pJ -= 5;
    if(pJ->getVida() == 0){
        pJ->eliminar();
    }
    destruir();
}

void Projetil::setPosition(float x, float y){
    personagem.setPosition(x, y);
}

void Projetil::ativar(){
    ativo = true;
}
void Projetil::destruir(){
    ativo = false;
    dt_exist = 0;
    personagem.setPosition(-100.f,-100.f);
}
void Projetil::executar(){
    if(ativo){
        float dx = 0, dy = 0, dt = 0;
        dt = Jogo::getDt();
        dt_exist += dt;
        vel_y = vel_y + 50.f*dt;
        dx = vel_x*dt;
        dy = vel_y*dt;
        movePos(dx, dy);
    }
    if(dt_exist > 7.5f){
        destruir();
    }
}
void Projetil::salvar(){

}
void Projetil::movePos(float x, float y){
    personagem.move(x, y);
}

void Projetil::setChefao(Personagens::Inim_chefao *pInim){
    pChefao = pInim;
}
void Projetil::setDir(float x, float y){
    vel_x = vel_projetil*x;
    vel_y = vel_projetil*y;
}
}//Fim namespace 

} // Fim do namespace Stalingrado
