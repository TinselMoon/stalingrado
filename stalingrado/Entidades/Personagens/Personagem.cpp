#include "Personagem.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {

Personagem::Personagem(int vida, const std::string& nomeTextura) : Entidades::Entidade(nomeTextura){
    num_vidas = vida;
    sf::FloatRect rectangle = personagem.getLocalBounds();
    personagem.setOrigin(rectangle.width/2.f, rectangle.height/2.f);
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
