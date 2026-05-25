#include "Personagem.hpp"

class Jogador;

namespace Personagens{
class Inimigo : public Personagens::Personagem{
protected:
    int nivel_maldade;

public:
    Inimigo(int vida, int maldade);
    Inimigo();
    ~Inimigo();
    void salvarDataBuffer();
    virtual void executar() = 0;
    virtual void danificar(Jogador* pJ) = 0;
    virtual void mover() = 0;
};
}
