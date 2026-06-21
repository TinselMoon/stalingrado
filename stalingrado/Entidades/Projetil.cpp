#include "Projetil.hpp"
#include "../States/Jogo.hpp"
#include "Personagens/Jogador.hpp"
#include "Personagens/Inim_chefao.hpp"

namespace Stalingrado {

namespace Entidades{
using namespace States;

Projetil::Projetil() : Entidade("Projetil"), vel_x(0), vel_y(0), vel_projetil(500.f), dt_exist(0){
    ativo = false;
    corpo.setPosition(-100.f, -100.f);
    mult_impulso = ((float)rand()/RAND_MAX)*0.5f + 0.4f;
}

Projetil::~Projetil(){

}

void Projetil::danificar(Personagens::Jogador *pJ){
    *pJ -= 5;
    pJ->setVelocidadeX(400.f);
    pJ->impulso(mult_impulso);
    if(pJ->getVida() == 0){
        pJ->eliminar();
    }
    destruir();
}

void Projetil::setPosition(float x, float y){
    corpo.setPosition(x, y);
}

void Projetil::ativar(){
    ativo = true;
}
void Projetil::destruir(){
    ativo = false;
    dt_exist = 0;
    corpo.setPosition(-100.f,-100.f);
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
void Projetil::salvar(std::ofstream& arquivo){

}
sf::Vector2f Projetil::getPosition() const{
    return corpo.getPosition();
}
float Projetil::getVelX() const{
    return vel_x;
}
float Projetil::getVelY() const{
    return vel_y;
}
float Projetil::getDtExist() const{
    return dt_exist;
}
void Projetil::restaurarEstado(bool ativoSalvo, float x, float y, float vx, float vy, float dtExist){
    ativo = ativoSalvo;
    corpo.setPosition(x, y);
    vel_x = vx;
    vel_y = vy;
    dt_exist = dtExist;
}
void Projetil::movePos(float x, float y){
    corpo.move(x, y);
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
