#pragma once
#include "../Personagem.hpp"


namespace Entidades {
namespace Personagens {
class Inimigo;
class Jogador : public Personagens::Personagem{
protected:
    int pontos;
public:
    Jogador(int vida);
    ~Jogador();
    void colidir(Inimigo* pIn);
    void executar();
    void salvar();
    void mover();
};
}

} // Fim do namespace Entidades
