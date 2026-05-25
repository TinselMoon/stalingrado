#pragma once
#include "../Inimigo.hpp"

namespace Personagens {
class Inim_facil : public Personagens::Inimigo{
private:
public:
    Inim_facil(int vida, int maldade);
    Inim_facil();
    ~Inim_facil();
    void danificar(Jogador *pJ);
    void executar();
    void salvar();
    void mover();
};

}
