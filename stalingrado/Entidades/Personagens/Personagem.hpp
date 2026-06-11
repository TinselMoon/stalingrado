#pragma once
#include "../Entidade.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {
class Personagem : public Entidades::Entidade {
protected:
    int num_vidas;
    float vel_x;
    float vel_y;
public:
    Personagem(int vida, const std::string& nomeTextura);
    ~Personagem();
    void salvarDataBuffer();
    void operator-=(int dano); //sobrecarga de operador para tirar vida do jogador (tomar dano).
    void movePos(float x, float y);
    void setVelocidadeX(float vx);
    void setVelocidadeY(float vy);
    float getVelX();
    float getVelY();
    sf::Vector2f getPos();
    int getVida();
    //void tomarDano(int dano);
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void mover();
};
}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
