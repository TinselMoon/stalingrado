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
    int nivel_maldade;
    float max_speed;
    float dt_movimento;
    float dt_dano;

public:
    Personagem(int vida, int nMaldade, float mSpeed, float dtMov, float dtDn, const std::string& nomeTextura);
    ~Personagem();
    void salvarDataBuffer();
    void operator-=(int dano); //sobrecarga de operador para tirar vida do personagem (perder vida).
    void operator+=(int bonus); //sobrecarga de operador para adicionar vida ao personagem (ganhar vida).
    void movePos(float x, float y);
    void setVelocidadeX(float vx);
    void setVelocidadeY(float vy);
    float getVelX();
    float getVelY();
    sf::Vector2f getPos();
    int getVida();
    virtual void danificar(Personagem* pPers) = 0;
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void mover();
};
}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
