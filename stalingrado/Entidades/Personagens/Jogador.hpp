#pragma once
#include "Personagem.hpp"
#include <SFML/Graphics.hpp>

namespace Stalingrado {


namespace Entidades {
namespace Personagens {
class Inimigo;
class Jogador : public Personagens::Personagem{
private:
    bool WisPressed;
protected:
    int pontos;
public:
    Jogador(int vida = 0);
    ~Jogador();
    void colidir(Inimigo* pIn);
    void lerMovimentacao();
    void executar();
    void salvar();
    void mover();
    //void desenhar();
};
}

} // Fim do namespace Entidades

} // Fim do namespace Stalingrado
