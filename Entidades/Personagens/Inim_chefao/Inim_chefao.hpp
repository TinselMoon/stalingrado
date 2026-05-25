#pragma once
#include "../Inimigo.hpp"

namespace Entidades {
namespace Personagens {
class Inim_chefao : public Personagens::Inimigo{
private:
public:
    Inim_chefao(int vida, int maldade);
    Inim_chefao();
    ~Inim_chefao();
    void danificar(Jogador *pJ);
    void executar();
    void salvar();
    void mover();
};

}

} // Fim do namespace Entidades
