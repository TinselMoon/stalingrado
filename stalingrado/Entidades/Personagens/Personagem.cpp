#include "Personagem.hpp"
#include "../../Jogo.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {

Personagem::Personagem(int vida, const std::string& nomeTextura) : Entidades::Entidade(nomeTextura){
    num_vidas = vida;
    sf::FloatRect rectangle = personagem.getLocalBounds();
    personagem.setOrigin(rectangle.width/2.f, rectangle.height/2.f);
    vel_x = vel_y = 0.f;
}

Personagem::~Personagem(){
    num_vidas = -1;
}
void Personagem::salvarDataBuffer(){

}

float Personagem::getVelX(){
    return vel_x;
}
float Personagem::getVelY(){
    return vel_y;
}

sf::Vector2f Personagem::getPos(){
    return personagem.getPosition();
}

void Personagem::movePos(float x, float y){
    personagem.move(x, y);
}

void Personagem::setVelocidadeX(float vx){
    vel_x = vx;
}
void Personagem::setVelocidadeY(float vy){
    vel_y = vy;
}

void Personagem::mover(){
    float dx = 0, dy = 0, dt = 0;
    dt = Jogo::getDt();
    setVelocidadeY(getVelY() + 1200.f*dt);
    dx = getVelX()*dt;
    dy = getVelY()*dt;
    personagem.move(dx, dy);
}

}
} // Fim dos namespaces

} // Fim do namespace Stalingrado
