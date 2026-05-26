#pragma once
#include "../Entidade.hpp"

namespace Stalingrado {

namespace Entidades{
class Projetil : public Entidade{
protected:
    bool ativo;
public:
    Projetil();
    ~Projetil();
    void executar();
    void salvar();
};
}

} // Fim do namespace Stalingrado
