#pragma once
#include "../Entidade.hpp"

namespace Stalingrado {

namespace Entidades {
namespace Personagens {
class Jogador;
class Personagem : public Entidade {
protected:
    int num_vidas;
    float vel_x;
    float vel_y;

public:
    Personagem(int vida, const std::string& nomeTextura);
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
    virtual const int getPontos() const = 0;
    void eliminar(Jogador *pJ = NULL);
    void setMorto();
    virtual void danificar(Personagem* pPers) = 0;
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void mover();
};
}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
